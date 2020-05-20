// Self
#include "ProcessSingleton_Linux.hpp"

// Project headers - Common
#include "Common/Macros/Logging.hpp"

// System headers
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

// C Standard Library
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

////////////////////////////////////////////////////////////////////////////////
// Defines
////////////////////////////////////////////////////////////////////////////////

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::HostPlatformClasses)

////////////////////////////////////////////////////////////////////////////////
// Global file scope variables
////////////////////////////////////////////////////////////////////////////////

int connectionSocket = INVALID_SOCKET;

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

bool
ProcessSingleton_Linux::Initialized()
{
  return isInitalized;
}

bool
ProcessSingleton_Linux::Running()
{
  return isRunning;
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

void
ProcessSingleton_Linux::Initialize(std::string const& applicationGUID)
{
  // Create a local socket
  connectionSocket = socket(AF_UNIX, SOCK_STREAM, 0);
  if (INVALID_SOCKET == connectionSocket) {
    auto lastError = errno;
    printf("socket failed with error: %d\n", lastError);

    return;
  }

  // Create an empty structure for portability
  sockaddr_un socketName{};

  // Prepare data for an abstract socket
  socketName.sun_path[0] = '\0';
  socketName.sun_family = AF_UNIX;
  std::strncpy(
    &(socketName.sun_path[1]),
    applicationGUID.c_str(),
    applicationGUID.length());

  auto addressLength = applicationGUID.length() + 1;

  // If 'bind()' fails the application is already started
  auto result = bind(
    connectionSocket,
    reinterpret_cast<sockaddr const*>(&socketName),
    addressLength);
  if (SOCKET_ERROR == result) {
    switch (errno) {
      case EADDRINUSE: {
        isRunning = true;

        break;
      }

      default: {
        ELogE("Socket error: bind() failed with error %d", errno);
      }
    }

    return;
  }

  isInitalized = true;
}

void
ProcessSingleton_Linux::Finalize()
{
  if (isInitalized) {
    // Close the socket to release the resources associated
    auto result = close(connectionSocket);
    if (SOCKET_ERROR == result) {
      ELogE("Socket error: 'closesocket()' failed with error %d", errno);
    }

    isInitalized = false;
  }
}

NAMESPACE_END(System::HostPlatformClasses)

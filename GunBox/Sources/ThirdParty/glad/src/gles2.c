#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glad/gles2.h>

#ifndef GLAD_IMPL_UTIL_C_
#define GLAD_IMPL_UTIL_C_

#ifdef _MSC_VER
#define GLAD_IMPL_UTIL_SSCANF sscanf_s
#else
#define GLAD_IMPL_UTIL_SSCANF sscanf
#endif

#endif /* GLAD_IMPL_UTIL_C_ */


int GLAD_GL_ES_VERSION_2_0 = 0;
int GLAD_GL_ES_VERSION_3_0 = 0;
int GLAD_GL_ES_VERSION_3_1 = 0;
int GLAD_GL_ES_VERSION_3_2 = 0;



PFNGLACTIVESHADERPROGRAMPROC glad_glActiveShaderProgram = NULL;
PFNGLACTIVETEXTUREPROC glad_glActiveTexture = NULL;
PFNGLATTACHSHADERPROC glad_glAttachShader = NULL;
PFNGLBEGINQUERYPROC glad_glBeginQuery = NULL;
PFNGLBEGINTRANSFORMFEEDBACKPROC glad_glBeginTransformFeedback = NULL;
PFNGLBINDATTRIBLOCATIONPROC glad_glBindAttribLocation = NULL;
PFNGLBINDBUFFERPROC glad_glBindBuffer = NULL;
PFNGLBINDBUFFERBASEPROC glad_glBindBufferBase = NULL;
PFNGLBINDBUFFERRANGEPROC glad_glBindBufferRange = NULL;
PFNGLBINDFRAMEBUFFERPROC glad_glBindFramebuffer = NULL;
PFNGLBINDIMAGETEXTUREPROC glad_glBindImageTexture = NULL;
PFNGLBINDPROGRAMPIPELINEPROC glad_glBindProgramPipeline = NULL;
PFNGLBINDRENDERBUFFERPROC glad_glBindRenderbuffer = NULL;
PFNGLBINDSAMPLERPROC glad_glBindSampler = NULL;
PFNGLBINDTEXTUREPROC glad_glBindTexture = NULL;
PFNGLBINDTRANSFORMFEEDBACKPROC glad_glBindTransformFeedback = NULL;
PFNGLBINDVERTEXARRAYPROC glad_glBindVertexArray = NULL;
PFNGLBINDVERTEXBUFFERPROC glad_glBindVertexBuffer = NULL;
PFNGLBLENDBARRIERPROC glad_glBlendBarrier = NULL;
PFNGLBLENDCOLORPROC glad_glBlendColor = NULL;
PFNGLBLENDEQUATIONPROC glad_glBlendEquation = NULL;
PFNGLBLENDEQUATIONSEPARATEPROC glad_glBlendEquationSeparate = NULL;
PFNGLBLENDEQUATIONSEPARATEIPROC glad_glBlendEquationSeparatei = NULL;
PFNGLBLENDEQUATIONIPROC glad_glBlendEquationi = NULL;
PFNGLBLENDFUNCPROC glad_glBlendFunc = NULL;
PFNGLBLENDFUNCSEPARATEPROC glad_glBlendFuncSeparate = NULL;
PFNGLBLENDFUNCSEPARATEIPROC glad_glBlendFuncSeparatei = NULL;
PFNGLBLENDFUNCIPROC glad_glBlendFunci = NULL;
PFNGLBLITFRAMEBUFFERPROC glad_glBlitFramebuffer = NULL;
PFNGLBUFFERDATAPROC glad_glBufferData = NULL;
PFNGLBUFFERSUBDATAPROC glad_glBufferSubData = NULL;
PFNGLCHECKFRAMEBUFFERSTATUSPROC glad_glCheckFramebufferStatus = NULL;
PFNGLCLEARPROC glad_glClear = NULL;
PFNGLCLEARBUFFERFIPROC glad_glClearBufferfi = NULL;
PFNGLCLEARBUFFERFVPROC glad_glClearBufferfv = NULL;
PFNGLCLEARBUFFERIVPROC glad_glClearBufferiv = NULL;
PFNGLCLEARBUFFERUIVPROC glad_glClearBufferuiv = NULL;
PFNGLCLEARCOLORPROC glad_glClearColor = NULL;
PFNGLCLEARDEPTHFPROC glad_glClearDepthf = NULL;
PFNGLCLEARSTENCILPROC glad_glClearStencil = NULL;
PFNGLCLIENTWAITSYNCPROC glad_glClientWaitSync = NULL;
PFNGLCOLORMASKPROC glad_glColorMask = NULL;
PFNGLCOLORMASKIPROC glad_glColorMaski = NULL;
PFNGLCOMPILESHADERPROC glad_glCompileShader = NULL;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glad_glCompressedTexImage2D = NULL;
PFNGLCOMPRESSEDTEXIMAGE3DPROC glad_glCompressedTexImage3D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glad_glCompressedTexSubImage2D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glad_glCompressedTexSubImage3D = NULL;
PFNGLCOPYBUFFERSUBDATAPROC glad_glCopyBufferSubData = NULL;
PFNGLCOPYIMAGESUBDATAPROC glad_glCopyImageSubData = NULL;
PFNGLCOPYTEXIMAGE2DPROC glad_glCopyTexImage2D = NULL;
PFNGLCOPYTEXSUBIMAGE2DPROC glad_glCopyTexSubImage2D = NULL;
PFNGLCOPYTEXSUBIMAGE3DPROC glad_glCopyTexSubImage3D = NULL;
PFNGLCREATEPROGRAMPROC glad_glCreateProgram = NULL;
PFNGLCREATESHADERPROC glad_glCreateShader = NULL;
PFNGLCREATESHADERPROGRAMVPROC glad_glCreateShaderProgramv = NULL;
PFNGLCULLFACEPROC glad_glCullFace = NULL;
PFNGLDEBUGMESSAGECALLBACKPROC glad_glDebugMessageCallback = NULL;
PFNGLDEBUGMESSAGECONTROLPROC glad_glDebugMessageControl = NULL;
PFNGLDEBUGMESSAGEINSERTPROC glad_glDebugMessageInsert = NULL;
PFNGLDELETEBUFFERSPROC glad_glDeleteBuffers = NULL;
PFNGLDELETEFRAMEBUFFERSPROC glad_glDeleteFramebuffers = NULL;
PFNGLDELETEPROGRAMPROC glad_glDeleteProgram = NULL;
PFNGLDELETEPROGRAMPIPELINESPROC glad_glDeleteProgramPipelines = NULL;
PFNGLDELETEQUERIESPROC glad_glDeleteQueries = NULL;
PFNGLDELETERENDERBUFFERSPROC glad_glDeleteRenderbuffers = NULL;
PFNGLDELETESAMPLERSPROC glad_glDeleteSamplers = NULL;
PFNGLDELETESHADERPROC glad_glDeleteShader = NULL;
PFNGLDELETESYNCPROC glad_glDeleteSync = NULL;
PFNGLDELETETEXTURESPROC glad_glDeleteTextures = NULL;
PFNGLDELETETRANSFORMFEEDBACKSPROC glad_glDeleteTransformFeedbacks = NULL;
PFNGLDELETEVERTEXARRAYSPROC glad_glDeleteVertexArrays = NULL;
PFNGLDEPTHFUNCPROC glad_glDepthFunc = NULL;
PFNGLDEPTHMASKPROC glad_glDepthMask = NULL;
PFNGLDEPTHRANGEFPROC glad_glDepthRangef = NULL;
PFNGLDETACHSHADERPROC glad_glDetachShader = NULL;
PFNGLDISABLEPROC glad_glDisable = NULL;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glad_glDisableVertexAttribArray = NULL;
PFNGLDISABLEIPROC glad_glDisablei = NULL;
PFNGLDISPATCHCOMPUTEPROC glad_glDispatchCompute = NULL;
PFNGLDISPATCHCOMPUTEINDIRECTPROC glad_glDispatchComputeIndirect = NULL;
PFNGLDRAWARRAYSPROC glad_glDrawArrays = NULL;
PFNGLDRAWARRAYSINDIRECTPROC glad_glDrawArraysIndirect = NULL;
PFNGLDRAWARRAYSINSTANCEDPROC glad_glDrawArraysInstanced = NULL;
PFNGLDRAWBUFFERSPROC glad_glDrawBuffers = NULL;
PFNGLDRAWELEMENTSPROC glad_glDrawElements = NULL;
PFNGLDRAWELEMENTSBASEVERTEXPROC glad_glDrawElementsBaseVertex = NULL;
PFNGLDRAWELEMENTSINDIRECTPROC glad_glDrawElementsIndirect = NULL;
PFNGLDRAWELEMENTSINSTANCEDPROC glad_glDrawElementsInstanced = NULL;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glad_glDrawElementsInstancedBaseVertex = NULL;
PFNGLDRAWRANGEELEMENTSPROC glad_glDrawRangeElements = NULL;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glad_glDrawRangeElementsBaseVertex = NULL;
PFNGLENABLEPROC glad_glEnable = NULL;
PFNGLENABLEVERTEXATTRIBARRAYPROC glad_glEnableVertexAttribArray = NULL;
PFNGLENABLEIPROC glad_glEnablei = NULL;
PFNGLENDQUERYPROC glad_glEndQuery = NULL;
PFNGLENDTRANSFORMFEEDBACKPROC glad_glEndTransformFeedback = NULL;
PFNGLFENCESYNCPROC glad_glFenceSync = NULL;
PFNGLFINISHPROC glad_glFinish = NULL;
PFNGLFLUSHPROC glad_glFlush = NULL;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC glad_glFlushMappedBufferRange = NULL;
PFNGLFRAMEBUFFERPARAMETERIPROC glad_glFramebufferParameteri = NULL;
PFNGLFRAMEBUFFERRENDERBUFFERPROC glad_glFramebufferRenderbuffer = NULL;
PFNGLFRAMEBUFFERTEXTUREPROC glad_glFramebufferTexture = NULL;
PFNGLFRAMEBUFFERTEXTURE2DPROC glad_glFramebufferTexture2D = NULL;
PFNGLFRAMEBUFFERTEXTURELAYERPROC glad_glFramebufferTextureLayer = NULL;
PFNGLFRONTFACEPROC glad_glFrontFace = NULL;
PFNGLGENBUFFERSPROC glad_glGenBuffers = NULL;
PFNGLGENFRAMEBUFFERSPROC glad_glGenFramebuffers = NULL;
PFNGLGENPROGRAMPIPELINESPROC glad_glGenProgramPipelines = NULL;
PFNGLGENQUERIESPROC glad_glGenQueries = NULL;
PFNGLGENRENDERBUFFERSPROC glad_glGenRenderbuffers = NULL;
PFNGLGENSAMPLERSPROC glad_glGenSamplers = NULL;
PFNGLGENTEXTURESPROC glad_glGenTextures = NULL;
PFNGLGENTRANSFORMFEEDBACKSPROC glad_glGenTransformFeedbacks = NULL;
PFNGLGENVERTEXARRAYSPROC glad_glGenVertexArrays = NULL;
PFNGLGENERATEMIPMAPPROC glad_glGenerateMipmap = NULL;
PFNGLGETACTIVEATTRIBPROC glad_glGetActiveAttrib = NULL;
PFNGLGETACTIVEUNIFORMPROC glad_glGetActiveUniform = NULL;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glad_glGetActiveUniformBlockName = NULL;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC glad_glGetActiveUniformBlockiv = NULL;
PFNGLGETACTIVEUNIFORMSIVPROC glad_glGetActiveUniformsiv = NULL;
PFNGLGETATTACHEDSHADERSPROC glad_glGetAttachedShaders = NULL;
PFNGLGETATTRIBLOCATIONPROC glad_glGetAttribLocation = NULL;
PFNGLGETBOOLEANI_VPROC glad_glGetBooleani_v = NULL;
PFNGLGETBOOLEANVPROC glad_glGetBooleanv = NULL;
PFNGLGETBUFFERPARAMETERI64VPROC glad_glGetBufferParameteri64v = NULL;
PFNGLGETBUFFERPARAMETERIVPROC glad_glGetBufferParameteriv = NULL;
PFNGLGETBUFFERPOINTERVPROC glad_glGetBufferPointerv = NULL;
PFNGLGETDEBUGMESSAGELOGPROC glad_glGetDebugMessageLog = NULL;
PFNGLGETERRORPROC glad_glGetError = NULL;
PFNGLGETFLOATVPROC glad_glGetFloatv = NULL;
PFNGLGETFRAGDATALOCATIONPROC glad_glGetFragDataLocation = NULL;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glad_glGetFramebufferAttachmentParameteriv = NULL;
PFNGLGETFRAMEBUFFERPARAMETERIVPROC glad_glGetFramebufferParameteriv = NULL;
PFNGLGETGRAPHICSRESETSTATUSPROC glad_glGetGraphicsResetStatus = NULL;
PFNGLGETINTEGER64I_VPROC glad_glGetInteger64i_v = NULL;
PFNGLGETINTEGER64VPROC glad_glGetInteger64v = NULL;
PFNGLGETINTEGERI_VPROC glad_glGetIntegeri_v = NULL;
PFNGLGETINTEGERVPROC glad_glGetIntegerv = NULL;
PFNGLGETINTERNALFORMATIVPROC glad_glGetInternalformativ = NULL;
PFNGLGETMULTISAMPLEFVPROC glad_glGetMultisamplefv = NULL;
PFNGLGETOBJECTLABELPROC glad_glGetObjectLabel = NULL;
PFNGLGETOBJECTPTRLABELPROC glad_glGetObjectPtrLabel = NULL;
PFNGLGETPOINTERVPROC glad_glGetPointerv = NULL;
PFNGLGETPROGRAMBINARYPROC glad_glGetProgramBinary = NULL;
PFNGLGETPROGRAMINFOLOGPROC glad_glGetProgramInfoLog = NULL;
PFNGLGETPROGRAMINTERFACEIVPROC glad_glGetProgramInterfaceiv = NULL;
PFNGLGETPROGRAMPIPELINEINFOLOGPROC glad_glGetProgramPipelineInfoLog = NULL;
PFNGLGETPROGRAMPIPELINEIVPROC glad_glGetProgramPipelineiv = NULL;
PFNGLGETPROGRAMRESOURCEINDEXPROC glad_glGetProgramResourceIndex = NULL;
PFNGLGETPROGRAMRESOURCELOCATIONPROC glad_glGetProgramResourceLocation = NULL;
PFNGLGETPROGRAMRESOURCENAMEPROC glad_glGetProgramResourceName = NULL;
PFNGLGETPROGRAMRESOURCEIVPROC glad_glGetProgramResourceiv = NULL;
PFNGLGETPROGRAMIVPROC glad_glGetProgramiv = NULL;
PFNGLGETQUERYOBJECTUIVPROC glad_glGetQueryObjectuiv = NULL;
PFNGLGETQUERYIVPROC glad_glGetQueryiv = NULL;
PFNGLGETRENDERBUFFERPARAMETERIVPROC glad_glGetRenderbufferParameteriv = NULL;
PFNGLGETSAMPLERPARAMETERIIVPROC glad_glGetSamplerParameterIiv = NULL;
PFNGLGETSAMPLERPARAMETERIUIVPROC glad_glGetSamplerParameterIuiv = NULL;
PFNGLGETSAMPLERPARAMETERFVPROC glad_glGetSamplerParameterfv = NULL;
PFNGLGETSAMPLERPARAMETERIVPROC glad_glGetSamplerParameteriv = NULL;
PFNGLGETSHADERINFOLOGPROC glad_glGetShaderInfoLog = NULL;
PFNGLGETSHADERPRECISIONFORMATPROC glad_glGetShaderPrecisionFormat = NULL;
PFNGLGETSHADERSOURCEPROC glad_glGetShaderSource = NULL;
PFNGLGETSHADERIVPROC glad_glGetShaderiv = NULL;
PFNGLGETSTRINGPROC glad_glGetString = NULL;
PFNGLGETSTRINGIPROC glad_glGetStringi = NULL;
PFNGLGETSYNCIVPROC glad_glGetSynciv = NULL;
PFNGLGETTEXLEVELPARAMETERFVPROC glad_glGetTexLevelParameterfv = NULL;
PFNGLGETTEXLEVELPARAMETERIVPROC glad_glGetTexLevelParameteriv = NULL;
PFNGLGETTEXPARAMETERIIVPROC glad_glGetTexParameterIiv = NULL;
PFNGLGETTEXPARAMETERIUIVPROC glad_glGetTexParameterIuiv = NULL;
PFNGLGETTEXPARAMETERFVPROC glad_glGetTexParameterfv = NULL;
PFNGLGETTEXPARAMETERIVPROC glad_glGetTexParameteriv = NULL;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glad_glGetTransformFeedbackVarying = NULL;
PFNGLGETUNIFORMBLOCKINDEXPROC glad_glGetUniformBlockIndex = NULL;
PFNGLGETUNIFORMINDICESPROC glad_glGetUniformIndices = NULL;
PFNGLGETUNIFORMLOCATIONPROC glad_glGetUniformLocation = NULL;
PFNGLGETUNIFORMFVPROC glad_glGetUniformfv = NULL;
PFNGLGETUNIFORMIVPROC glad_glGetUniformiv = NULL;
PFNGLGETUNIFORMUIVPROC glad_glGetUniformuiv = NULL;
PFNGLGETVERTEXATTRIBIIVPROC glad_glGetVertexAttribIiv = NULL;
PFNGLGETVERTEXATTRIBIUIVPROC glad_glGetVertexAttribIuiv = NULL;
PFNGLGETVERTEXATTRIBPOINTERVPROC glad_glGetVertexAttribPointerv = NULL;
PFNGLGETVERTEXATTRIBFVPROC glad_glGetVertexAttribfv = NULL;
PFNGLGETVERTEXATTRIBIVPROC glad_glGetVertexAttribiv = NULL;
PFNGLGETNUNIFORMFVPROC glad_glGetnUniformfv = NULL;
PFNGLGETNUNIFORMIVPROC glad_glGetnUniformiv = NULL;
PFNGLGETNUNIFORMUIVPROC glad_glGetnUniformuiv = NULL;
PFNGLHINTPROC glad_glHint = NULL;
PFNGLINVALIDATEFRAMEBUFFERPROC glad_glInvalidateFramebuffer = NULL;
PFNGLINVALIDATESUBFRAMEBUFFERPROC glad_glInvalidateSubFramebuffer = NULL;
PFNGLISBUFFERPROC glad_glIsBuffer = NULL;
PFNGLISENABLEDPROC glad_glIsEnabled = NULL;
PFNGLISENABLEDIPROC glad_glIsEnabledi = NULL;
PFNGLISFRAMEBUFFERPROC glad_glIsFramebuffer = NULL;
PFNGLISPROGRAMPROC glad_glIsProgram = NULL;
PFNGLISPROGRAMPIPELINEPROC glad_glIsProgramPipeline = NULL;
PFNGLISQUERYPROC glad_glIsQuery = NULL;
PFNGLISRENDERBUFFERPROC glad_glIsRenderbuffer = NULL;
PFNGLISSAMPLERPROC glad_glIsSampler = NULL;
PFNGLISSHADERPROC glad_glIsShader = NULL;
PFNGLISSYNCPROC glad_glIsSync = NULL;
PFNGLISTEXTUREPROC glad_glIsTexture = NULL;
PFNGLISTRANSFORMFEEDBACKPROC glad_glIsTransformFeedback = NULL;
PFNGLISVERTEXARRAYPROC glad_glIsVertexArray = NULL;
PFNGLLINEWIDTHPROC glad_glLineWidth = NULL;
PFNGLLINKPROGRAMPROC glad_glLinkProgram = NULL;
PFNGLMAPBUFFERRANGEPROC glad_glMapBufferRange = NULL;
PFNGLMEMORYBARRIERPROC glad_glMemoryBarrier = NULL;
PFNGLMEMORYBARRIERBYREGIONPROC glad_glMemoryBarrierByRegion = NULL;
PFNGLMINSAMPLESHADINGPROC glad_glMinSampleShading = NULL;
PFNGLOBJECTLABELPROC glad_glObjectLabel = NULL;
PFNGLOBJECTPTRLABELPROC glad_glObjectPtrLabel = NULL;
PFNGLPATCHPARAMETERIPROC glad_glPatchParameteri = NULL;
PFNGLPAUSETRANSFORMFEEDBACKPROC glad_glPauseTransformFeedback = NULL;
PFNGLPIXELSTOREIPROC glad_glPixelStorei = NULL;
PFNGLPOLYGONOFFSETPROC glad_glPolygonOffset = NULL;
PFNGLPOPDEBUGGROUPPROC glad_glPopDebugGroup = NULL;
PFNGLPRIMITIVEBOUNDINGBOXPROC glad_glPrimitiveBoundingBox = NULL;
PFNGLPROGRAMBINARYPROC glad_glProgramBinary = NULL;
PFNGLPROGRAMPARAMETERIPROC glad_glProgramParameteri = NULL;
PFNGLPROGRAMUNIFORM1FPROC glad_glProgramUniform1f = NULL;
PFNGLPROGRAMUNIFORM1FVPROC glad_glProgramUniform1fv = NULL;
PFNGLPROGRAMUNIFORM1IPROC glad_glProgramUniform1i = NULL;
PFNGLPROGRAMUNIFORM1IVPROC glad_glProgramUniform1iv = NULL;
PFNGLPROGRAMUNIFORM1UIPROC glad_glProgramUniform1ui = NULL;
PFNGLPROGRAMUNIFORM1UIVPROC glad_glProgramUniform1uiv = NULL;
PFNGLPROGRAMUNIFORM2FPROC glad_glProgramUniform2f = NULL;
PFNGLPROGRAMUNIFORM2FVPROC glad_glProgramUniform2fv = NULL;
PFNGLPROGRAMUNIFORM2IPROC glad_glProgramUniform2i = NULL;
PFNGLPROGRAMUNIFORM2IVPROC glad_glProgramUniform2iv = NULL;
PFNGLPROGRAMUNIFORM2UIPROC glad_glProgramUniform2ui = NULL;
PFNGLPROGRAMUNIFORM2UIVPROC glad_glProgramUniform2uiv = NULL;
PFNGLPROGRAMUNIFORM3FPROC glad_glProgramUniform3f = NULL;
PFNGLPROGRAMUNIFORM3FVPROC glad_glProgramUniform3fv = NULL;
PFNGLPROGRAMUNIFORM3IPROC glad_glProgramUniform3i = NULL;
PFNGLPROGRAMUNIFORM3IVPROC glad_glProgramUniform3iv = NULL;
PFNGLPROGRAMUNIFORM3UIPROC glad_glProgramUniform3ui = NULL;
PFNGLPROGRAMUNIFORM3UIVPROC glad_glProgramUniform3uiv = NULL;
PFNGLPROGRAMUNIFORM4FPROC glad_glProgramUniform4f = NULL;
PFNGLPROGRAMUNIFORM4FVPROC glad_glProgramUniform4fv = NULL;
PFNGLPROGRAMUNIFORM4IPROC glad_glProgramUniform4i = NULL;
PFNGLPROGRAMUNIFORM4IVPROC glad_glProgramUniform4iv = NULL;
PFNGLPROGRAMUNIFORM4UIPROC glad_glProgramUniform4ui = NULL;
PFNGLPROGRAMUNIFORM4UIVPROC glad_glProgramUniform4uiv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2FVPROC glad_glProgramUniformMatrix2fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glad_glProgramUniformMatrix2x3fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glad_glProgramUniformMatrix2x4fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3FVPROC glad_glProgramUniformMatrix3fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glad_glProgramUniformMatrix3x2fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glad_glProgramUniformMatrix3x4fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4FVPROC glad_glProgramUniformMatrix4fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glad_glProgramUniformMatrix4x2fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glad_glProgramUniformMatrix4x3fv = NULL;
PFNGLPUSHDEBUGGROUPPROC glad_glPushDebugGroup = NULL;
PFNGLREADBUFFERPROC glad_glReadBuffer = NULL;
PFNGLREADPIXELSPROC glad_glReadPixels = NULL;
PFNGLREADNPIXELSPROC glad_glReadnPixels = NULL;
PFNGLRELEASESHADERCOMPILERPROC glad_glReleaseShaderCompiler = NULL;
PFNGLRENDERBUFFERSTORAGEPROC glad_glRenderbufferStorage = NULL;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glad_glRenderbufferStorageMultisample = NULL;
PFNGLRESUMETRANSFORMFEEDBACKPROC glad_glResumeTransformFeedback = NULL;
PFNGLSAMPLECOVERAGEPROC glad_glSampleCoverage = NULL;
PFNGLSAMPLEMASKIPROC glad_glSampleMaski = NULL;
PFNGLSAMPLERPARAMETERIIVPROC glad_glSamplerParameterIiv = NULL;
PFNGLSAMPLERPARAMETERIUIVPROC glad_glSamplerParameterIuiv = NULL;
PFNGLSAMPLERPARAMETERFPROC glad_glSamplerParameterf = NULL;
PFNGLSAMPLERPARAMETERFVPROC glad_glSamplerParameterfv = NULL;
PFNGLSAMPLERPARAMETERIPROC glad_glSamplerParameteri = NULL;
PFNGLSAMPLERPARAMETERIVPROC glad_glSamplerParameteriv = NULL;
PFNGLSCISSORPROC glad_glScissor = NULL;
PFNGLSHADERBINARYPROC glad_glShaderBinary = NULL;
PFNGLSHADERSOURCEPROC glad_glShaderSource = NULL;
PFNGLSTENCILFUNCPROC glad_glStencilFunc = NULL;
PFNGLSTENCILFUNCSEPARATEPROC glad_glStencilFuncSeparate = NULL;
PFNGLSTENCILMASKPROC glad_glStencilMask = NULL;
PFNGLSTENCILMASKSEPARATEPROC glad_glStencilMaskSeparate = NULL;
PFNGLSTENCILOPPROC glad_glStencilOp = NULL;
PFNGLSTENCILOPSEPARATEPROC glad_glStencilOpSeparate = NULL;
PFNGLTEXBUFFERPROC glad_glTexBuffer = NULL;
PFNGLTEXBUFFERRANGEPROC glad_glTexBufferRange = NULL;
PFNGLTEXIMAGE2DPROC glad_glTexImage2D = NULL;
PFNGLTEXIMAGE3DPROC glad_glTexImage3D = NULL;
PFNGLTEXPARAMETERIIVPROC glad_glTexParameterIiv = NULL;
PFNGLTEXPARAMETERIUIVPROC glad_glTexParameterIuiv = NULL;
PFNGLTEXPARAMETERFPROC glad_glTexParameterf = NULL;
PFNGLTEXPARAMETERFVPROC glad_glTexParameterfv = NULL;
PFNGLTEXPARAMETERIPROC glad_glTexParameteri = NULL;
PFNGLTEXPARAMETERIVPROC glad_glTexParameteriv = NULL;
PFNGLTEXSTORAGE2DPROC glad_glTexStorage2D = NULL;
PFNGLTEXSTORAGE2DMULTISAMPLEPROC glad_glTexStorage2DMultisample = NULL;
PFNGLTEXSTORAGE3DPROC glad_glTexStorage3D = NULL;
PFNGLTEXSTORAGE3DMULTISAMPLEPROC glad_glTexStorage3DMultisample = NULL;
PFNGLTEXSUBIMAGE2DPROC glad_glTexSubImage2D = NULL;
PFNGLTEXSUBIMAGE3DPROC glad_glTexSubImage3D = NULL;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC glad_glTransformFeedbackVaryings = NULL;
PFNGLUNIFORM1FPROC glad_glUniform1f = NULL;
PFNGLUNIFORM1FVPROC glad_glUniform1fv = NULL;
PFNGLUNIFORM1IPROC glad_glUniform1i = NULL;
PFNGLUNIFORM1IVPROC glad_glUniform1iv = NULL;
PFNGLUNIFORM1UIPROC glad_glUniform1ui = NULL;
PFNGLUNIFORM1UIVPROC glad_glUniform1uiv = NULL;
PFNGLUNIFORM2FPROC glad_glUniform2f = NULL;
PFNGLUNIFORM2FVPROC glad_glUniform2fv = NULL;
PFNGLUNIFORM2IPROC glad_glUniform2i = NULL;
PFNGLUNIFORM2IVPROC glad_glUniform2iv = NULL;
PFNGLUNIFORM2UIPROC glad_glUniform2ui = NULL;
PFNGLUNIFORM2UIVPROC glad_glUniform2uiv = NULL;
PFNGLUNIFORM3FPROC glad_glUniform3f = NULL;
PFNGLUNIFORM3FVPROC glad_glUniform3fv = NULL;
PFNGLUNIFORM3IPROC glad_glUniform3i = NULL;
PFNGLUNIFORM3IVPROC glad_glUniform3iv = NULL;
PFNGLUNIFORM3UIPROC glad_glUniform3ui = NULL;
PFNGLUNIFORM3UIVPROC glad_glUniform3uiv = NULL;
PFNGLUNIFORM4FPROC glad_glUniform4f = NULL;
PFNGLUNIFORM4FVPROC glad_glUniform4fv = NULL;
PFNGLUNIFORM4IPROC glad_glUniform4i = NULL;
PFNGLUNIFORM4IVPROC glad_glUniform4iv = NULL;
PFNGLUNIFORM4UIPROC glad_glUniform4ui = NULL;
PFNGLUNIFORM4UIVPROC glad_glUniform4uiv = NULL;
PFNGLUNIFORMBLOCKBINDINGPROC glad_glUniformBlockBinding = NULL;
PFNGLUNIFORMMATRIX2FVPROC glad_glUniformMatrix2fv = NULL;
PFNGLUNIFORMMATRIX2X3FVPROC glad_glUniformMatrix2x3fv = NULL;
PFNGLUNIFORMMATRIX2X4FVPROC glad_glUniformMatrix2x4fv = NULL;
PFNGLUNIFORMMATRIX3FVPROC glad_glUniformMatrix3fv = NULL;
PFNGLUNIFORMMATRIX3X2FVPROC glad_glUniformMatrix3x2fv = NULL;
PFNGLUNIFORMMATRIX3X4FVPROC glad_glUniformMatrix3x4fv = NULL;
PFNGLUNIFORMMATRIX4FVPROC glad_glUniformMatrix4fv = NULL;
PFNGLUNIFORMMATRIX4X2FVPROC glad_glUniformMatrix4x2fv = NULL;
PFNGLUNIFORMMATRIX4X3FVPROC glad_glUniformMatrix4x3fv = NULL;
PFNGLUNMAPBUFFERPROC glad_glUnmapBuffer = NULL;
PFNGLUSEPROGRAMPROC glad_glUseProgram = NULL;
PFNGLUSEPROGRAMSTAGESPROC glad_glUseProgramStages = NULL;
PFNGLVALIDATEPROGRAMPROC glad_glValidateProgram = NULL;
PFNGLVALIDATEPROGRAMPIPELINEPROC glad_glValidateProgramPipeline = NULL;
PFNGLVERTEXATTRIB1FPROC glad_glVertexAttrib1f = NULL;
PFNGLVERTEXATTRIB1FVPROC glad_glVertexAttrib1fv = NULL;
PFNGLVERTEXATTRIB2FPROC glad_glVertexAttrib2f = NULL;
PFNGLVERTEXATTRIB2FVPROC glad_glVertexAttrib2fv = NULL;
PFNGLVERTEXATTRIB3FPROC glad_glVertexAttrib3f = NULL;
PFNGLVERTEXATTRIB3FVPROC glad_glVertexAttrib3fv = NULL;
PFNGLVERTEXATTRIB4FPROC glad_glVertexAttrib4f = NULL;
PFNGLVERTEXATTRIB4FVPROC glad_glVertexAttrib4fv = NULL;
PFNGLVERTEXATTRIBBINDINGPROC glad_glVertexAttribBinding = NULL;
PFNGLVERTEXATTRIBDIVISORPROC glad_glVertexAttribDivisor = NULL;
PFNGLVERTEXATTRIBFORMATPROC glad_glVertexAttribFormat = NULL;
PFNGLVERTEXATTRIBI4IPROC glad_glVertexAttribI4i = NULL;
PFNGLVERTEXATTRIBI4IVPROC glad_glVertexAttribI4iv = NULL;
PFNGLVERTEXATTRIBI4UIPROC glad_glVertexAttribI4ui = NULL;
PFNGLVERTEXATTRIBI4UIVPROC glad_glVertexAttribI4uiv = NULL;
PFNGLVERTEXATTRIBIFORMATPROC glad_glVertexAttribIFormat = NULL;
PFNGLVERTEXATTRIBIPOINTERPROC glad_glVertexAttribIPointer = NULL;
PFNGLVERTEXATTRIBPOINTERPROC glad_glVertexAttribPointer = NULL;
PFNGLVERTEXBINDINGDIVISORPROC glad_glVertexBindingDivisor = NULL;
PFNGLVIEWPORTPROC glad_glViewport = NULL;
PFNGLWAITSYNCPROC glad_glWaitSync = NULL;


static void glad_gl_load_GL_ES_VERSION_2_0( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ES_VERSION_2_0) return;
    glActiveTexture = (PFNGLACTIVETEXTUREPROC) load("glActiveTexture", userptr);
    glAttachShader = (PFNGLATTACHSHADERPROC) load("glAttachShader", userptr);
    glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC) load("glBindAttribLocation", userptr);
    glBindBuffer = (PFNGLBINDBUFFERPROC) load("glBindBuffer", userptr);
    glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC) load("glBindFramebuffer", userptr);
    glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC) load("glBindRenderbuffer", userptr);
    glBindTexture = (PFNGLBINDTEXTUREPROC) load("glBindTexture", userptr);
    glBlendColor = (PFNGLBLENDCOLORPROC) load("glBlendColor", userptr);
    glBlendEquation = (PFNGLBLENDEQUATIONPROC) load("glBlendEquation", userptr);
    glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC) load("glBlendEquationSeparate", userptr);
    glBlendFunc = (PFNGLBLENDFUNCPROC) load("glBlendFunc", userptr);
    glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC) load("glBlendFuncSeparate", userptr);
    glBufferData = (PFNGLBUFFERDATAPROC) load("glBufferData", userptr);
    glBufferSubData = (PFNGLBUFFERSUBDATAPROC) load("glBufferSubData", userptr);
    glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC) load("glCheckFramebufferStatus", userptr);
    glClear = (PFNGLCLEARPROC) load("glClear", userptr);
    glClearColor = (PFNGLCLEARCOLORPROC) load("glClearColor", userptr);
    glClearDepthf = (PFNGLCLEARDEPTHFPROC) load("glClearDepthf", userptr);
    glClearStencil = (PFNGLCLEARSTENCILPROC) load("glClearStencil", userptr);
    glColorMask = (PFNGLCOLORMASKPROC) load("glColorMask", userptr);
    glCompileShader = (PFNGLCOMPILESHADERPROC) load("glCompileShader", userptr);
    glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC) load("glCompressedTexImage2D", userptr);
    glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) load("glCompressedTexSubImage2D", userptr);
    glCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC) load("glCopyTexImage2D", userptr);
    glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC) load("glCopyTexSubImage2D", userptr);
    glCreateProgram = (PFNGLCREATEPROGRAMPROC) load("glCreateProgram", userptr);
    glCreateShader = (PFNGLCREATESHADERPROC) load("glCreateShader", userptr);
    glCullFace = (PFNGLCULLFACEPROC) load("glCullFace", userptr);
    glDeleteBuffers = (PFNGLDELETEBUFFERSPROC) load("glDeleteBuffers", userptr);
    glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC) load("glDeleteFramebuffers", userptr);
    glDeleteProgram = (PFNGLDELETEPROGRAMPROC) load("glDeleteProgram", userptr);
    glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC) load("glDeleteRenderbuffers", userptr);
    glDeleteShader = (PFNGLDELETESHADERPROC) load("glDeleteShader", userptr);
    glDeleteTextures = (PFNGLDELETETEXTURESPROC) load("glDeleteTextures", userptr);
    glDepthFunc = (PFNGLDEPTHFUNCPROC) load("glDepthFunc", userptr);
    glDepthMask = (PFNGLDEPTHMASKPROC) load("glDepthMask", userptr);
    glDepthRangef = (PFNGLDEPTHRANGEFPROC) load("glDepthRangef", userptr);
    glDetachShader = (PFNGLDETACHSHADERPROC) load("glDetachShader", userptr);
    glDisable = (PFNGLDISABLEPROC) load("glDisable", userptr);
    glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC) load("glDisableVertexAttribArray", userptr);
    glDrawArrays = (PFNGLDRAWARRAYSPROC) load("glDrawArrays", userptr);
    glDrawElements = (PFNGLDRAWELEMENTSPROC) load("glDrawElements", userptr);
    glEnable = (PFNGLENABLEPROC) load("glEnable", userptr);
    glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC) load("glEnableVertexAttribArray", userptr);
    glFinish = (PFNGLFINISHPROC) load("glFinish", userptr);
    glFlush = (PFNGLFLUSHPROC) load("glFlush", userptr);
    glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC) load("glFramebufferRenderbuffer", userptr);
    glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC) load("glFramebufferTexture2D", userptr);
    glFrontFace = (PFNGLFRONTFACEPROC) load("glFrontFace", userptr);
    glGenBuffers = (PFNGLGENBUFFERSPROC) load("glGenBuffers", userptr);
    glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC) load("glGenFramebuffers", userptr);
    glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC) load("glGenRenderbuffers", userptr);
    glGenTextures = (PFNGLGENTEXTURESPROC) load("glGenTextures", userptr);
    glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC) load("glGenerateMipmap", userptr);
    glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC) load("glGetActiveAttrib", userptr);
    glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC) load("glGetActiveUniform", userptr);
    glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC) load("glGetAttachedShaders", userptr);
    glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC) load("glGetAttribLocation", userptr);
    glGetBooleanv = (PFNGLGETBOOLEANVPROC) load("glGetBooleanv", userptr);
    glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC) load("glGetBufferParameteriv", userptr);
    glGetError = (PFNGLGETERRORPROC) load("glGetError", userptr);
    glGetFloatv = (PFNGLGETFLOATVPROC) load("glGetFloatv", userptr);
    glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC) load("glGetFramebufferAttachmentParameteriv", userptr);
    glGetIntegerv = (PFNGLGETINTEGERVPROC) load("glGetIntegerv", userptr);
    glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC) load("glGetProgramInfoLog", userptr);
    glGetProgramiv = (PFNGLGETPROGRAMIVPROC) load("glGetProgramiv", userptr);
    glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC) load("glGetRenderbufferParameteriv", userptr);
    glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC) load("glGetShaderInfoLog", userptr);
    glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC) load("glGetShaderPrecisionFormat", userptr);
    glGetShaderSource = (PFNGLGETSHADERSOURCEPROC) load("glGetShaderSource", userptr);
    glGetShaderiv = (PFNGLGETSHADERIVPROC) load("glGetShaderiv", userptr);
    glGetString = (PFNGLGETSTRINGPROC) load("glGetString", userptr);
    glGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC) load("glGetTexParameterfv", userptr);
    glGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC) load("glGetTexParameteriv", userptr);
    glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC) load("glGetUniformLocation", userptr);
    glGetUniformfv = (PFNGLGETUNIFORMFVPROC) load("glGetUniformfv", userptr);
    glGetUniformiv = (PFNGLGETUNIFORMIVPROC) load("glGetUniformiv", userptr);
    glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC) load("glGetVertexAttribPointerv", userptr);
    glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC) load("glGetVertexAttribfv", userptr);
    glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC) load("glGetVertexAttribiv", userptr);
    glHint = (PFNGLHINTPROC) load("glHint", userptr);
    glIsBuffer = (PFNGLISBUFFERPROC) load("glIsBuffer", userptr);
    glIsEnabled = (PFNGLISENABLEDPROC) load("glIsEnabled", userptr);
    glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC) load("glIsFramebuffer", userptr);
    glIsProgram = (PFNGLISPROGRAMPROC) load("glIsProgram", userptr);
    glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC) load("glIsRenderbuffer", userptr);
    glIsShader = (PFNGLISSHADERPROC) load("glIsShader", userptr);
    glIsTexture = (PFNGLISTEXTUREPROC) load("glIsTexture", userptr);
    glLineWidth = (PFNGLLINEWIDTHPROC) load("glLineWidth", userptr);
    glLinkProgram = (PFNGLLINKPROGRAMPROC) load("glLinkProgram", userptr);
    glPixelStorei = (PFNGLPIXELSTOREIPROC) load("glPixelStorei", userptr);
    glPolygonOffset = (PFNGLPOLYGONOFFSETPROC) load("glPolygonOffset", userptr);
    glReadPixels = (PFNGLREADPIXELSPROC) load("glReadPixels", userptr);
    glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC) load("glReleaseShaderCompiler", userptr);
    glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC) load("glRenderbufferStorage", userptr);
    glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC) load("glSampleCoverage", userptr);
    glScissor = (PFNGLSCISSORPROC) load("glScissor", userptr);
    glShaderBinary = (PFNGLSHADERBINARYPROC) load("glShaderBinary", userptr);
    glShaderSource = (PFNGLSHADERSOURCEPROC) load("glShaderSource", userptr);
    glStencilFunc = (PFNGLSTENCILFUNCPROC) load("glStencilFunc", userptr);
    glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC) load("glStencilFuncSeparate", userptr);
    glStencilMask = (PFNGLSTENCILMASKPROC) load("glStencilMask", userptr);
    glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC) load("glStencilMaskSeparate", userptr);
    glStencilOp = (PFNGLSTENCILOPPROC) load("glStencilOp", userptr);
    glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC) load("glStencilOpSeparate", userptr);
    glTexImage2D = (PFNGLTEXIMAGE2DPROC) load("glTexImage2D", userptr);
    glTexParameterf = (PFNGLTEXPARAMETERFPROC) load("glTexParameterf", userptr);
    glTexParameterfv = (PFNGLTEXPARAMETERFVPROC) load("glTexParameterfv", userptr);
    glTexParameteri = (PFNGLTEXPARAMETERIPROC) load("glTexParameteri", userptr);
    glTexParameteriv = (PFNGLTEXPARAMETERIVPROC) load("glTexParameteriv", userptr);
    glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC) load("glTexSubImage2D", userptr);
    glUniform1f = (PFNGLUNIFORM1FPROC) load("glUniform1f", userptr);
    glUniform1fv = (PFNGLUNIFORM1FVPROC) load("glUniform1fv", userptr);
    glUniform1i = (PFNGLUNIFORM1IPROC) load("glUniform1i", userptr);
    glUniform1iv = (PFNGLUNIFORM1IVPROC) load("glUniform1iv", userptr);
    glUniform2f = (PFNGLUNIFORM2FPROC) load("glUniform2f", userptr);
    glUniform2fv = (PFNGLUNIFORM2FVPROC) load("glUniform2fv", userptr);
    glUniform2i = (PFNGLUNIFORM2IPROC) load("glUniform2i", userptr);
    glUniform2iv = (PFNGLUNIFORM2IVPROC) load("glUniform2iv", userptr);
    glUniform3f = (PFNGLUNIFORM3FPROC) load("glUniform3f", userptr);
    glUniform3fv = (PFNGLUNIFORM3FVPROC) load("glUniform3fv", userptr);
    glUniform3i = (PFNGLUNIFORM3IPROC) load("glUniform3i", userptr);
    glUniform3iv = (PFNGLUNIFORM3IVPROC) load("glUniform3iv", userptr);
    glUniform4f = (PFNGLUNIFORM4FPROC) load("glUniform4f", userptr);
    glUniform4fv = (PFNGLUNIFORM4FVPROC) load("glUniform4fv", userptr);
    glUniform4i = (PFNGLUNIFORM4IPROC) load("glUniform4i", userptr);
    glUniform4iv = (PFNGLUNIFORM4IVPROC) load("glUniform4iv", userptr);
    glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC) load("glUniformMatrix2fv", userptr);
    glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC) load("glUniformMatrix3fv", userptr);
    glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC) load("glUniformMatrix4fv", userptr);
    glUseProgram = (PFNGLUSEPROGRAMPROC) load("glUseProgram", userptr);
    glValidateProgram = (PFNGLVALIDATEPROGRAMPROC) load("glValidateProgram", userptr);
    glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC) load("glVertexAttrib1f", userptr);
    glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC) load("glVertexAttrib1fv", userptr);
    glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC) load("glVertexAttrib2f", userptr);
    glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC) load("glVertexAttrib2fv", userptr);
    glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC) load("glVertexAttrib3f", userptr);
    glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC) load("glVertexAttrib3fv", userptr);
    glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC) load("glVertexAttrib4f", userptr);
    glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC) load("glVertexAttrib4fv", userptr);
    glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC) load("glVertexAttribPointer", userptr);
    glViewport = (PFNGLVIEWPORTPROC) load("glViewport", userptr);
}
static void glad_gl_load_GL_ES_VERSION_3_0( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ES_VERSION_3_0) return;
    glBeginQuery = (PFNGLBEGINQUERYPROC) load("glBeginQuery", userptr);
    glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC) load("glBeginTransformFeedback", userptr);
    glBindBufferBase = (PFNGLBINDBUFFERBASEPROC) load("glBindBufferBase", userptr);
    glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC) load("glBindBufferRange", userptr);
    glBindSampler = (PFNGLBINDSAMPLERPROC) load("glBindSampler", userptr);
    glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC) load("glBindTransformFeedback", userptr);
    glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC) load("glBindVertexArray", userptr);
    glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC) load("glBlitFramebuffer", userptr);
    glClearBufferfi = (PFNGLCLEARBUFFERFIPROC) load("glClearBufferfi", userptr);
    glClearBufferfv = (PFNGLCLEARBUFFERFVPROC) load("glClearBufferfv", userptr);
    glClearBufferiv = (PFNGLCLEARBUFFERIVPROC) load("glClearBufferiv", userptr);
    glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC) load("glClearBufferuiv", userptr);
    glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC) load("glClientWaitSync", userptr);
    glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC) load("glCompressedTexImage3D", userptr);
    glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) load("glCompressedTexSubImage3D", userptr);
    glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC) load("glCopyBufferSubData", userptr);
    glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC) load("glCopyTexSubImage3D", userptr);
    glDeleteQueries = (PFNGLDELETEQUERIESPROC) load("glDeleteQueries", userptr);
    glDeleteSamplers = (PFNGLDELETESAMPLERSPROC) load("glDeleteSamplers", userptr);
    glDeleteSync = (PFNGLDELETESYNCPROC) load("glDeleteSync", userptr);
    glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC) load("glDeleteTransformFeedbacks", userptr);
    glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC) load("glDeleteVertexArrays", userptr);
    glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC) load("glDrawArraysInstanced", userptr);
    glDrawBuffers = (PFNGLDRAWBUFFERSPROC) load("glDrawBuffers", userptr);
    glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC) load("glDrawElementsInstanced", userptr);
    glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC) load("glDrawRangeElements", userptr);
    glEndQuery = (PFNGLENDQUERYPROC) load("glEndQuery", userptr);
    glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC) load("glEndTransformFeedback", userptr);
    glFenceSync = (PFNGLFENCESYNCPROC) load("glFenceSync", userptr);
    glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC) load("glFlushMappedBufferRange", userptr);
    glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC) load("glFramebufferTextureLayer", userptr);
    glGenQueries = (PFNGLGENQUERIESPROC) load("glGenQueries", userptr);
    glGenSamplers = (PFNGLGENSAMPLERSPROC) load("glGenSamplers", userptr);
    glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC) load("glGenTransformFeedbacks", userptr);
    glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC) load("glGenVertexArrays", userptr);
    glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC) load("glGetActiveUniformBlockName", userptr);
    glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC) load("glGetActiveUniformBlockiv", userptr);
    glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC) load("glGetActiveUniformsiv", userptr);
    glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC) load("glGetBufferParameteri64v", userptr);
    glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC) load("glGetBufferPointerv", userptr);
    glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC) load("glGetFragDataLocation", userptr);
    glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC) load("glGetInteger64i_v", userptr);
    glGetInteger64v = (PFNGLGETINTEGER64VPROC) load("glGetInteger64v", userptr);
    glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC) load("glGetIntegeri_v", userptr);
    glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC) load("glGetInternalformativ", userptr);
    glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC) load("glGetProgramBinary", userptr);
    glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC) load("glGetQueryObjectuiv", userptr);
    glGetQueryiv = (PFNGLGETQUERYIVPROC) load("glGetQueryiv", userptr);
    glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC) load("glGetSamplerParameterfv", userptr);
    glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC) load("glGetSamplerParameteriv", userptr);
    glGetStringi = (PFNGLGETSTRINGIPROC) load("glGetStringi", userptr);
    glGetSynciv = (PFNGLGETSYNCIVPROC) load("glGetSynciv", userptr);
    glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC) load("glGetTransformFeedbackVarying", userptr);
    glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC) load("glGetUniformBlockIndex", userptr);
    glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC) load("glGetUniformIndices", userptr);
    glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC) load("glGetUniformuiv", userptr);
    glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC) load("glGetVertexAttribIiv", userptr);
    glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC) load("glGetVertexAttribIuiv", userptr);
    glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC) load("glInvalidateFramebuffer", userptr);
    glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC) load("glInvalidateSubFramebuffer", userptr);
    glIsQuery = (PFNGLISQUERYPROC) load("glIsQuery", userptr);
    glIsSampler = (PFNGLISSAMPLERPROC) load("glIsSampler", userptr);
    glIsSync = (PFNGLISSYNCPROC) load("glIsSync", userptr);
    glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC) load("glIsTransformFeedback", userptr);
    glIsVertexArray = (PFNGLISVERTEXARRAYPROC) load("glIsVertexArray", userptr);
    glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC) load("glMapBufferRange", userptr);
    glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC) load("glPauseTransformFeedback", userptr);
    glProgramBinary = (PFNGLPROGRAMBINARYPROC) load("glProgramBinary", userptr);
    glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC) load("glProgramParameteri", userptr);
    glReadBuffer = (PFNGLREADBUFFERPROC) load("glReadBuffer", userptr);
    glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC) load("glRenderbufferStorageMultisample", userptr);
    glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC) load("glResumeTransformFeedback", userptr);
    glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC) load("glSamplerParameterf", userptr);
    glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC) load("glSamplerParameterfv", userptr);
    glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC) load("glSamplerParameteri", userptr);
    glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC) load("glSamplerParameteriv", userptr);
    glTexImage3D = (PFNGLTEXIMAGE3DPROC) load("glTexImage3D", userptr);
    glTexStorage2D = (PFNGLTEXSTORAGE2DPROC) load("glTexStorage2D", userptr);
    glTexStorage3D = (PFNGLTEXSTORAGE3DPROC) load("glTexStorage3D", userptr);
    glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC) load("glTexSubImage3D", userptr);
    glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC) load("glTransformFeedbackVaryings", userptr);
    glUniform1ui = (PFNGLUNIFORM1UIPROC) load("glUniform1ui", userptr);
    glUniform1uiv = (PFNGLUNIFORM1UIVPROC) load("glUniform1uiv", userptr);
    glUniform2ui = (PFNGLUNIFORM2UIPROC) load("glUniform2ui", userptr);
    glUniform2uiv = (PFNGLUNIFORM2UIVPROC) load("glUniform2uiv", userptr);
    glUniform3ui = (PFNGLUNIFORM3UIPROC) load("glUniform3ui", userptr);
    glUniform3uiv = (PFNGLUNIFORM3UIVPROC) load("glUniform3uiv", userptr);
    glUniform4ui = (PFNGLUNIFORM4UIPROC) load("glUniform4ui", userptr);
    glUniform4uiv = (PFNGLUNIFORM4UIVPROC) load("glUniform4uiv", userptr);
    glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC) load("glUniformBlockBinding", userptr);
    glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC) load("glUniformMatrix2x3fv", userptr);
    glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC) load("glUniformMatrix2x4fv", userptr);
    glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC) load("glUniformMatrix3x2fv", userptr);
    glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC) load("glUniformMatrix3x4fv", userptr);
    glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC) load("glUniformMatrix4x2fv", userptr);
    glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC) load("glUniformMatrix4x3fv", userptr);
    glUnmapBuffer = (PFNGLUNMAPBUFFERPROC) load("glUnmapBuffer", userptr);
    glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC) load("glVertexAttribDivisor", userptr);
    glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC) load("glVertexAttribI4i", userptr);
    glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC) load("glVertexAttribI4iv", userptr);
    glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC) load("glVertexAttribI4ui", userptr);
    glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC) load("glVertexAttribI4uiv", userptr);
    glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC) load("glVertexAttribIPointer", userptr);
    glWaitSync = (PFNGLWAITSYNCPROC) load("glWaitSync", userptr);
}
static void glad_gl_load_GL_ES_VERSION_3_1( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ES_VERSION_3_1) return;
    glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC) load("glActiveShaderProgram", userptr);
    glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC) load("glBindImageTexture", userptr);
    glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC) load("glBindProgramPipeline", userptr);
    glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC) load("glBindVertexBuffer", userptr);
    glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC) load("glCreateShaderProgramv", userptr);
    glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC) load("glDeleteProgramPipelines", userptr);
    glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC) load("glDispatchCompute", userptr);
    glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC) load("glDispatchComputeIndirect", userptr);
    glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC) load("glDrawArraysIndirect", userptr);
    glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC) load("glDrawElementsIndirect", userptr);
    glFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC) load("glFramebufferParameteri", userptr);
    glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC) load("glGenProgramPipelines", userptr);
    glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC) load("glGetBooleani_v", userptr);
    glGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC) load("glGetFramebufferParameteriv", userptr);
    glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC) load("glGetMultisamplefv", userptr);
    glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC) load("glGetProgramInterfaceiv", userptr);
    glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC) load("glGetProgramPipelineInfoLog", userptr);
    glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC) load("glGetProgramPipelineiv", userptr);
    glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC) load("glGetProgramResourceIndex", userptr);
    glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC) load("glGetProgramResourceLocation", userptr);
    glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC) load("glGetProgramResourceName", userptr);
    glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC) load("glGetProgramResourceiv", userptr);
    glGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC) load("glGetTexLevelParameterfv", userptr);
    glGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC) load("glGetTexLevelParameteriv", userptr);
    glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC) load("glIsProgramPipeline", userptr);
    glMemoryBarrier = (PFNGLMEMORYBARRIERPROC) load("glMemoryBarrier", userptr);
    glMemoryBarrierByRegion = (PFNGLMEMORYBARRIERBYREGIONPROC) load("glMemoryBarrierByRegion", userptr);
    glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC) load("glProgramUniform1f", userptr);
    glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC) load("glProgramUniform1fv", userptr);
    glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC) load("glProgramUniform1i", userptr);
    glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC) load("glProgramUniform1iv", userptr);
    glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC) load("glProgramUniform1ui", userptr);
    glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC) load("glProgramUniform1uiv", userptr);
    glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC) load("glProgramUniform2f", userptr);
    glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC) load("glProgramUniform2fv", userptr);
    glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC) load("glProgramUniform2i", userptr);
    glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC) load("glProgramUniform2iv", userptr);
    glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC) load("glProgramUniform2ui", userptr);
    glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC) load("glProgramUniform2uiv", userptr);
    glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC) load("glProgramUniform3f", userptr);
    glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC) load("glProgramUniform3fv", userptr);
    glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC) load("glProgramUniform3i", userptr);
    glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC) load("glProgramUniform3iv", userptr);
    glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC) load("glProgramUniform3ui", userptr);
    glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC) load("glProgramUniform3uiv", userptr);
    glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC) load("glProgramUniform4f", userptr);
    glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC) load("glProgramUniform4fv", userptr);
    glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC) load("glProgramUniform4i", userptr);
    glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC) load("glProgramUniform4iv", userptr);
    glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC) load("glProgramUniform4ui", userptr);
    glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC) load("glProgramUniform4uiv", userptr);
    glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC) load("glProgramUniformMatrix2fv", userptr);
    glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC) load("glProgramUniformMatrix2x3fv", userptr);
    glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC) load("glProgramUniformMatrix2x4fv", userptr);
    glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC) load("glProgramUniformMatrix3fv", userptr);
    glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC) load("glProgramUniformMatrix3x2fv", userptr);
    glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC) load("glProgramUniformMatrix3x4fv", userptr);
    glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC) load("glProgramUniformMatrix4fv", userptr);
    glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC) load("glProgramUniformMatrix4x2fv", userptr);
    glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC) load("glProgramUniformMatrix4x3fv", userptr);
    glSampleMaski = (PFNGLSAMPLEMASKIPROC) load("glSampleMaski", userptr);
    glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC) load("glTexStorage2DMultisample", userptr);
    glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC) load("glUseProgramStages", userptr);
    glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC) load("glValidateProgramPipeline", userptr);
    glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC) load("glVertexAttribBinding", userptr);
    glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC) load("glVertexAttribFormat", userptr);
    glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC) load("glVertexAttribIFormat", userptr);
    glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC) load("glVertexBindingDivisor", userptr);
}
static void glad_gl_load_GL_ES_VERSION_3_2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ES_VERSION_3_2) return;
    glBlendBarrier = (PFNGLBLENDBARRIERPROC) load("glBlendBarrier", userptr);
    glBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC) load("glBlendEquationSeparatei", userptr);
    glBlendEquationi = (PFNGLBLENDEQUATIONIPROC) load("glBlendEquationi", userptr);
    glBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC) load("glBlendFuncSeparatei", userptr);
    glBlendFunci = (PFNGLBLENDFUNCIPROC) load("glBlendFunci", userptr);
    glColorMaski = (PFNGLCOLORMASKIPROC) load("glColorMaski", userptr);
    glCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC) load("glCopyImageSubData", userptr);
    glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC) load("glDebugMessageCallback", userptr);
    glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC) load("glDebugMessageControl", userptr);
    glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC) load("glDebugMessageInsert", userptr);
    glDisablei = (PFNGLDISABLEIPROC) load("glDisablei", userptr);
    glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC) load("glDrawElementsBaseVertex", userptr);
    glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC) load("glDrawElementsInstancedBaseVertex", userptr);
    glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC) load("glDrawRangeElementsBaseVertex", userptr);
    glEnablei = (PFNGLENABLEIPROC) load("glEnablei", userptr);
    glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC) load("glFramebufferTexture", userptr);
    glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC) load("glGetDebugMessageLog", userptr);
    glGetGraphicsResetStatus = (PFNGLGETGRAPHICSRESETSTATUSPROC) load("glGetGraphicsResetStatus", userptr);
    glGetObjectLabel = (PFNGLGETOBJECTLABELPROC) load("glGetObjectLabel", userptr);
    glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC) load("glGetObjectPtrLabel", userptr);
    glGetPointerv = (PFNGLGETPOINTERVPROC) load("glGetPointerv", userptr);
    glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC) load("glGetSamplerParameterIiv", userptr);
    glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC) load("glGetSamplerParameterIuiv", userptr);
    glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC) load("glGetTexParameterIiv", userptr);
    glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC) load("glGetTexParameterIuiv", userptr);
    glGetnUniformfv = (PFNGLGETNUNIFORMFVPROC) load("glGetnUniformfv", userptr);
    glGetnUniformiv = (PFNGLGETNUNIFORMIVPROC) load("glGetnUniformiv", userptr);
    glGetnUniformuiv = (PFNGLGETNUNIFORMUIVPROC) load("glGetnUniformuiv", userptr);
    glIsEnabledi = (PFNGLISENABLEDIPROC) load("glIsEnabledi", userptr);
    glMinSampleShading = (PFNGLMINSAMPLESHADINGPROC) load("glMinSampleShading", userptr);
    glObjectLabel = (PFNGLOBJECTLABELPROC) load("glObjectLabel", userptr);
    glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC) load("glObjectPtrLabel", userptr);
    glPatchParameteri = (PFNGLPATCHPARAMETERIPROC) load("glPatchParameteri", userptr);
    glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC) load("glPopDebugGroup", userptr);
    glPrimitiveBoundingBox = (PFNGLPRIMITIVEBOUNDINGBOXPROC) load("glPrimitiveBoundingBox", userptr);
    glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC) load("glPushDebugGroup", userptr);
    glReadnPixels = (PFNGLREADNPIXELSPROC) load("glReadnPixels", userptr);
    glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC) load("glSamplerParameterIiv", userptr);
    glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC) load("glSamplerParameterIuiv", userptr);
    glTexBuffer = (PFNGLTEXBUFFERPROC) load("glTexBuffer", userptr);
    glTexBufferRange = (PFNGLTEXBUFFERRANGEPROC) load("glTexBufferRange", userptr);
    glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC) load("glTexParameterIiv", userptr);
    glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC) load("glTexParameterIuiv", userptr);
    glTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC) load("glTexStorage3DMultisample", userptr);
}



#if defined(GL_ES_VERSION_3_0) || defined(GL_VERSION_3_0)
#define GLAD_GL_IS_SOME_NEW_VERSION 1
#else
#define GLAD_GL_IS_SOME_NEW_VERSION 0
#endif

static int glad_gl_get_extensions( int version, const char **out_exts, unsigned int *out_num_exts_i, char ***out_exts_i) {
#if GLAD_GL_IS_SOME_NEW_VERSION
    if(GLAD_VERSION_MAJOR(version) < 3) {
#else
    (void) version;
    (void) out_num_exts_i;
    (void) out_exts_i;
#endif
        if (glGetString == NULL) {
            return 0;
        }
        *out_exts = (const char *)glGetString(GL_EXTENSIONS);
#if GLAD_GL_IS_SOME_NEW_VERSION
    } else {
        unsigned int index = 0;
        unsigned int num_exts_i = 0;
        char **exts_i = NULL;
        if (glGetStringi == NULL || glGetIntegerv == NULL) {
            return 0;
        }
        glGetIntegerv(GL_NUM_EXTENSIONS, (int*) &num_exts_i);
        if (num_exts_i > 0) {
            exts_i = (char **) malloc(num_exts_i * (sizeof *exts_i));
        }
        if (exts_i == NULL) {
            return 0;
        }
        for(index = 0; index < num_exts_i; index++) {
            const char *gl_str_tmp = (const char*) glGetStringi(GL_EXTENSIONS, index);
            size_t len = strlen(gl_str_tmp) + 1;

            char *local_str = (char*) malloc(len * sizeof(char));
            if(local_str != NULL) {
                memcpy(local_str, gl_str_tmp, len * sizeof(char));
            }

            exts_i[index] = local_str;
        }

        *out_num_exts_i = num_exts_i;
        *out_exts_i = exts_i;
    }
#endif
    return 1;
}
static void glad_gl_free_extensions(char **exts_i, unsigned int num_exts_i) {
    if (exts_i != NULL) {
        unsigned int index;
        for(index = 0; index < num_exts_i; index++) {
            free((void *) (exts_i[index]));
        }
        free((void *)exts_i);
        exts_i = NULL;
    }
}
static int glad_gl_has_extension(int version, const char *exts, unsigned int num_exts_i, char **exts_i, const char *ext) {
    if(GLAD_VERSION_MAJOR(version) < 3 || !GLAD_GL_IS_SOME_NEW_VERSION) {
        const char *extensions;
        const char *loc;
        const char *terminator;
        extensions = exts;
        if(extensions == NULL || ext == NULL) {
            return 0;
        }
        while(1) {
            loc = strstr(extensions, ext);
            if(loc == NULL) {
                return 0;
            }
            terminator = loc + strlen(ext);
            if((loc == extensions || *(loc - 1) == ' ') &&
                (*terminator == ' ' || *terminator == '\0')) {
                return 1;
            }
            extensions = terminator;
        }
    } else {
        unsigned int index;
        for(index = 0; index < num_exts_i; index++) {
            const char *e = exts_i[index];
            if(strcmp(e, ext) == 0) {
                return 1;
            }
        }
    }
    return 0;
}

static GLADapiproc glad_gl_get_proc_from_userptr(const char* name, void *userptr) {
    return (GLAD_GNUC_EXTENSION (GLADapiproc (*)(const char *name)) userptr)(name);
}

static int glad_gl_find_extensions_gles2( int version) {
    const char *exts = NULL;
    unsigned int num_exts_i = 0;
    char **exts_i = NULL;
    if (!glad_gl_get_extensions(version, &exts, &num_exts_i, &exts_i)) return 0;

    (void) glad_gl_has_extension;

    glad_gl_free_extensions(exts_i, num_exts_i);

    return 1;
}

static int glad_gl_find_core_gles2(void) {
    int i, major, minor;
    const char* version;
    const char* prefixes[] = {
        "OpenGL ES-CM ",
        "OpenGL ES-CL ",
        "OpenGL ES ",
        NULL
    };
    version = (const char*) glGetString(GL_VERSION);
    if (!version) return 0;
    for (i = 0;  prefixes[i];  i++) {
        const size_t length = strlen(prefixes[i]);
        if (strncmp(version, prefixes[i], length) == 0) {
            version += length;
            break;
        }
    }

    GLAD_IMPL_UTIL_SSCANF(version, "%d.%d", &major, &minor);

    GLAD_GL_ES_VERSION_2_0 = (major == 2 && minor >= 0) || major > 2;
    GLAD_GL_ES_VERSION_3_0 = (major == 3 && minor >= 0) || major > 3;
    GLAD_GL_ES_VERSION_3_1 = (major == 3 && minor >= 1) || major > 3;
    GLAD_GL_ES_VERSION_3_2 = (major == 3 && minor >= 2) || major > 3;

    return GLAD_MAKE_VERSION(major, minor);
}

int gladLoadGLES2UserPtr( GLADuserptrloadfunc load, void *userptr) {
    int version;

    glGetString = (PFNGLGETSTRINGPROC) load("glGetString", userptr);
    if(glGetString == NULL) return 0;
    if(glGetString(GL_VERSION) == NULL) return 0;
    version = glad_gl_find_core_gles2();

    glad_gl_load_GL_ES_VERSION_2_0(load, userptr);
    glad_gl_load_GL_ES_VERSION_3_0(load, userptr);
    glad_gl_load_GL_ES_VERSION_3_1(load, userptr);
    glad_gl_load_GL_ES_VERSION_3_2(load, userptr);

    if (!glad_gl_find_extensions_gles2(version)) return 0;



    return version;
}


int gladLoadGLES2( GLADloadfunc load) {
    return gladLoadGLES2UserPtr( glad_gl_get_proc_from_userptr, GLAD_GNUC_EXTENSION (void*) load);
}





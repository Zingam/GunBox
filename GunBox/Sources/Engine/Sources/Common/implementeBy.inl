template<typename Class>
implementedBy<Class>::implementedBy()
  : o_ptr{ std::make_unique<Class>() }
{}

add_llvm_library ( LLVMCSE301 MODULE
	ArrayChecks.cpp
	NullChecks.cpp
	TypeAssigner.cpp
	TypeChecker.cpp
	
	PLUGIN_TOOL
	opt
	)

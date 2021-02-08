#pragma once
#ifdef TYRANT_DLL_EXP
	#define TYRANT_API __declspec(dllexport)
#else
	#define TYRANT_API __declspec(dllimport)
#endif

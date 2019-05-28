I-Logix-RPY-Archive version 4.0.4 C++
{ IProject 
	- _UserColors = { IRPYRawContainer 
		- size = 16;
		- value = 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 
	}
	- _defaultSubsystem = { ISubsystemHandle 
		- _m2Class = "ISubsystem";
		- _filename = "Default.sbs";
		- _subsystem = "";
		- _class = "";
		- _name = "Default";
		- _id = GUID 4582fb6c-0ad0-11d7-b329-00c04f680d9d;
	}
	- _component = { IHandle 
		- _m2Class = "IComponent";
		- _filename = "AnimationComponent.cmp";
		- _subsystem = "";
		- _class = "";
		- _name = "AnimationComponent";
		- _id = GUID 0a783ff3-b74b-4411-9da7-87e5d8088c53;
	}
	- Multiplicities = { IRPYRawContainer 
		- size = 4;
		- value = 
		{ IMultiplicityItem 
			- _name = "1";
			- _count = -1;
		}
		{ IMultiplicityItem 
			- _name = "*";
			- _count = -1;
		}
		{ IMultiplicityItem 
			- _name = "0,1";
			- _count = -1;
		}
		{ IMultiplicityItem 
			- _name = "1..*";
			- _count = -1;
		}
	}
	- Subsystems = { IRPYRawContainer 
		- size = 3;
		- value = 
		{ ISubsystem 
			- fileName = "Default";
			- _id = GUID 4582fb6c-0ad0-11d7-b329-00c04f680d9d;
		}
		{ ISubsystem 
			- fileName = "ReverseEngineering";
			- _id = GUID 3c7868b9-0f2c-4eb4-a757-efcccc3e2fb5;
		}
		{ ISubsystem 
			- fileName = "GuidancePkg";
			- _id = GUID e57df4ae-c7c0-4684-a34b-61f6e934aed0;
		}
	}
	- Diagrams = { IRPYRawContainer 
		- size = 2;
		- value = 
		{ IDiagram 
			- fileName = "GuidanceModels";
			- _id = GUID 4582fb76-0ad0-11d7-b329-00c04f680d9d;
		}
		{ IDiagram 
			- fileName = "PhysicalModels";
			- _id = GUID 1c1329d7-f3c0-4b1a-a3b4-64073ffb0a6e;
		}
	}
	- MSCS = { IRPYRawContainer 
		- size = 0;
	}
	- Components = { IRPYRawContainer 
		- size = 2;
		- value = 
		{ IComponent 
			- fileName = "DefaultComponent";
			- _id = GUID 4582fb72-0ad0-11d7-b329-00c04f680d9d;
		}
		{ IComponent 
			- fileName = "AnimationComponent";
			- _id = GUID 0a783ff3-b74b-4411-9da7-87e5d8088c53;
		}
	}
	- UCDiagrams = { IRPYRawContainer 
		- size = 0;
	}
	- ComponentDiagrams = { IRPYRawContainer 
		- size = 0;
	}
	- DeploymentDiagrams = { IRPYRawContainer 
		- size = 0;
	}
	- CollaborationDiagrams = { IRPYRawContainer 
		- size = 0;
	}
}


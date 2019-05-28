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
		- _id = GUID 23de58ff-7f57-4eb1-9dd5-0308fb505795;
	}
	- _component = { IHandle 
		- _m2Class = "IComponent";
		- _filename = "DefaultComponent.cmp";
		- _subsystem = "";
		- _class = "";
		- _name = "DefaultComponent";
		- _id = GUID d9e1d23e-6158-41ac-af31-01ddf98997a9;
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
		- size = 4;
		- value = 
		{ ISubsystem 
			- fileName = "Default";
			- _id = GUID 23de58ff-7f57-4eb1-9dd5-0308fb505795;
		}
		{ ISubsystem 
			- fileName = "ProcessModels";
			- _id = GUID 0988d413-962a-4fad-9570-19658fdc0eab;
		}
		{ ISubsystem 
			- fileName = "ReverseEngineering";
			- _id = GUID 89cb7ed0-2efd-46ad-ad38-f0cf301d5084;
		}
		{ ISubsystem 
			- fileName = "BallDemo";
			- _id = GUID dfef4c84-66df-455f-8010-deda6274d5bd;
		}
	}
	- Diagrams = { IRPYRawContainer 
		- size = 2;
		- value = 
		{ IDiagram 
			- fileName = "Reactor_Components";
			- _id = GUID 785bd510-88e0-47b3-bd71-7ae17b46dd09;
			- _name = "Reactor Components";
		}
		{ IDiagram 
			- fileName = "BouncingBallDemo";
			- _id = GUID cee6dafb-e305-4f94-9670-70821620e40f;
		}
	}
	- MSCS = { IRPYRawContainer 
		- size = 0;
	}
	- Components = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ IComponent 
			- fileName = "DefaultComponent";
			- _id = GUID d9e1d23e-6158-41ac-af31-01ddf98997a9;
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


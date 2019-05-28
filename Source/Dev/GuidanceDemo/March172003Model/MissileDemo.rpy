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
		- _filename = "AnimationComComponent.cmp";
		- _subsystem = "";
		- _class = "";
		- _name = "AnimationComComponent";
		- _id = GUID d26546d1-231e-11d7-b334-00c04f680d9d;
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
		- size = 10;
		- value = 
		{ ISubsystem 
			- fileName = "Default";
			- _id = GUID 4582fb6c-0ad0-11d7-b329-00c04f680d9d;
		}
		{ ISubsystem 
			- fileName = "AirframePkg";
			- _id = GUID e57df4ae-c7c0-4684-a34b-61f6e934aed0;
		}
		{ ISubsystem 
			- fileName = "GuidancePkg";
			- _id = GUID 48747585-d7db-4893-aea1-35e124e95403;
		}
		{ ISubsystem 
			- fileName = "AutopilotPkg";
			- _id = GUID c9142634-dee8-4f23-9ab2-94629976d079;
		}
		{ ISubsystem 
			- fileName = "Application";
			- _id = GUID b8c65d75-16b0-11d7-b32e-00c04f680d9d;
		}
		{ ISubsystem 
			- fileName = "TrackingSubsystemPkg";
			- _id = GUID 48655bb2-120d-40c8-b6b2-5fbfff52ea49;
		}
		{ ISubsystem 
			- fileName = "TargetPkg";
			- _id = GUID 9d763caf-f44a-4d2e-82ea-44a15b60ea2a;
		}
		{ ISubsystem 
			- fileName = "DisplayPkg";
			- _id = GUID 1f4df77a-ce15-4b4b-9f30-a2b94de5daf8;
		}
		{ ISubsystem 
			- fileName = "LibraryPkg";
			- _id = GUID f7ea1d29-db32-4756-bf15-fef5352c82ba;
		}
		{ ISubsystem 
			- fileName = "Communications";
			- _id = GUID 65f0c28b-8845-4c04-b7f6-62c8af5a83e5;
		}
	}
	- Diagrams = { IRPYRawContainer 
		- size = 3;
		- value = 
		{ IDiagram 
			- fileName = "AutopilotModels";
			- _id = GUID 6fe1d6f7-34ea-448f-a3a7-9df64c9c5b42;
		}
		{ IDiagram 
			- fileName = "SeekerSubsystemModels";
			- _id = GUID bcfd28d4-2a5e-11d7-b346-00c04f680d9d;
		}
		{ IDiagram 
			- fileName = "MissileGuidanceApplication";
			- _id = GUID 34fae592-6a76-466a-bc98-ff2df6618888;
		}
	}
	- MSCS = { IRPYRawContainer 
		- size = 0;
	}
	- Components = { IRPYRawContainer 
		- size = 3;
		- value = 
		{ IComponent 
			- fileName = "AnimationComponent";
			- _id = GUID 0a783ff3-b74b-4411-9da7-87e5d8088c53;
		}
		{ IComponent 
			- fileName = "DefaultComponent";
			- _id = GUID 4582fb72-0ad0-11d7-b329-00c04f680d9d;
		}
		{ IComponent 
			- fileName = "AnimationComComponent";
			- _id = GUID d26546d1-231e-11d7-b334-00c04f680d9d;
		}
	}
	- UCDiagrams = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ IUCDiagram 
			- fileName = "GuidedMissileControlSystem";
			- _id = GUID 06e2ab3d-c677-4fb5-927b-7b1561fc210a;
		}
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


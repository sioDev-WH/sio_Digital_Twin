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
		- _id = GUID 9fcee889-9879-48b2-875c-62ca01308855;
	}
	- _component = { IHandle 
		- _m2Class = "IComponent";
		- _filename = "AnimationComponent.cmp";
		- _subsystem = "";
		- _class = "";
		- _name = "AnimationComponent";
		- _id = GUID c17f6d6a-a5c5-42f3-abf7-6805a7fca26f;
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
		- size = 13;
		- value = 
		{ ISubsystem 
			- fileName = "Default";
			- _id = GUID 9fcee889-9879-48b2-875c-62ca01308855;
		}
		{ ISubsystem 
			- fileName = "StandardModels";
			- _id = GUID a2236308-c3da-4241-90a9-c1711c52e9f4;
		}
		{ ISubsystem 
			- fileName = "TransmissionModels";
			- _id = GUID 7caa7464-2b8a-4465-8d85-fb8fef46bd60;
		}
		{ ISubsystem 
			- fileName = "TransmissionControlModels";
			- _id = GUID 4e9450f2-fe60-4001-a990-d065fd57f1cb;
		}
		{ ISubsystem 
			- fileName = "VehicleModels";
			- _id = GUID a7a94d15-ada1-46b6-a54b-8424efd5595d;
		}
		{ ISubsystem 
			- fileName = "GUIModels";
			- _id = GUID 376c0f1c-16a6-4c5e-92c2-a714945c0fa1;
		}
		{ ISubsystem 
			- fileName = "Application";
			- _id = GUID 4733a771-c671-4ffe-87f0-f44d8854f1c3;
		}
		{ ISubsystem 
			- fileName = "ReverseEngineering";
			- _id = GUID 13a45ede-34de-429b-88b2-f8a88356a644;
		}
		{ ISubsystem 
			- fileName = "UI";
			- _id = GUID 06e73ac4-2cd8-11d7-b349-00c04f680d9d;
		}
		{ ISubsystem 
			- fileName = "DemoApp";
			- _id = GUID 16b05e75-80af-40ae-a849-94bb5e7e4c1d;
		}
		{ ISubsystem 
			- fileName = "Application1";
			- _id = GUID be0f965b-8e33-498e-8f89-5a5e5174ceb2;
		}
		{ ISubsystem 
			- fileName = "DiscreteTransmissionModels";
			- _id = GUID 9f1ed50f-c3e5-42c5-b6ca-e736c51d1bb3;
		}
		{ ISubsystem 
			- fileName = "AppSimple";
			- _id = GUID 39e523aa-b778-4336-b3ca-0d980f05b6ae;
		}
	}
	- Diagrams = { IRPYRawContainer 
		- size = 14;
		- value = 
		{ IDiagram 
			- fileName = "Actuator";
			- _id = GUID 6737987e-a981-477a-a21b-75221d6abd7d;
		}
		{ IDiagram 
			- fileName = "StandardModels";
			- _id = GUID bd9592ed-66d0-4ee7-b828-4a0049463cce;
		}
		{ IDiagram 
			- fileName = "ClutchModels";
			- _id = GUID eaa68394-a34a-4ca5-9b7d-633a81bd28d0;
		}
		{ IDiagram 
			- fileName = "ClutchSchedule";
			- _id = GUID af9f1386-17f9-4c2c-a293-27a3655352aa;
		}
		{ IDiagram 
			- fileName = "TransmissionController";
			- _id = GUID 75a27a5e-5263-40b7-a2ff-3025b913a0c7;
		}
		{ IDiagram 
			- fileName = "Engine";
			- _id = GUID 5301e90d-2a3b-4b0c-b678-2f19c6b19483;
		}
		{ IDiagram 
			- fileName = "Ravigneaux";
			- _id = GUID 10b45dc3-0e28-4dc2-aaf0-1991bc14a435;
		}
		{ IDiagram 
			- fileName = "TorqueConverter";
			- _id = GUID ece0b895-5523-47e2-8898-885449cf5ea4;
		}
		{ IDiagram 
			- fileName = "Vehicle";
			- _id = GUID 0e67ec45-4943-41c0-a6cb-487edf515d4c;
		}
		{ IDiagram 
			- fileName = "Gears";
			- _id = GUID 4c8c343a-b03a-4511-9493-40f3060562d8;
		}
		{ IDiagram 
			- fileName = "Application";
			- _id = GUID 4eeced33-1702-4b52-833f-7066bc702ace;
		}
		{ IDiagram 
			- fileName = "DriveTrain";
			- _id = GUID 262a1300-99da-421d-947a-de40c32b8877;
		}
		{ IDiagram 
			- fileName = "DriveTrainApplication";
			- _id = GUID 4a32655c-c6dc-4841-96d8-8e5d7fbe3b01;
		}
		{ IDiagram 
			- fileName = "DrivetrainSubsystem";
			- _id = GUID 93db3c04-62ec-4b5d-b920-587c10c97415;
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
			- _id = GUID c37924db-5baf-44fc-a324-ac84ddbcb484;
		}
		{ IComponent 
			- fileName = "AnimationComponent";
			- _id = GUID c17f6d6a-a5c5-42f3-abf7-6805a7fca26f;
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


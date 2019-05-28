I-Logix-RPY-Archive version 4.1.8 C++
{ IProject 
	- _ownerHandle = { IHandle 
		- _m2Class = "";
	}
	- _id = GUID 0277e2d9-be35-4d00-aa6a-faf45aca5718;
	- _myState = 8192;
	- _properties = { IPropertyContainer 
		- Subjects = { IRPYRawContainer 
			- size = 3;
			- value = 
			{ IPropertySubject 
				- _Name = "CG";
				- Metaclasses = { IRPYRawContainer 
					- size = 2;
					- value = 
					{ IPropertyMetaclass 
						- _Name = "Relation";
						- Properties = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IProperty 
								- _Name = "InstanceBasedLinking";
								- _Value = "False";
								- _Type = Bool;
							}
						}
					}
					{ IPropertyMetaclass 
						- _Name = "Type";
						- Properties = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IProperty 
								- _Name = "Animate";
								- _Value = "Force";
								- _Type = Enum;
								- _ExtraTypeInfo = "Force,True,False";
							}
						}
					}
				}
			}
			{ IPropertySubject 
				- _Name = "CPP_CG";
				- Metaclasses = { IRPYRawContainer 
					- size = 6;
					- value = 
					{ IPropertyMetaclass 
						- _Name = "Attribute";
						- Properties = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IProperty 
								- _Name = "MarkPrologEpilogInAnnotations";
								- _Value = "None";
								- _Type = Enum;
								- _ExtraTypeInfo = "None, Ignore, Auto";
							}
						}
					}
					{ IPropertyMetaclass 
						- _Name = "Class";
						- Properties = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IProperty 
								- _Name = "MarkPrologEpilogInAnnotations";
								- _Value = "None";
								- _Type = Enum;
								- _ExtraTypeInfo = "None, Ignore, Auto";
							}
						}
					}
					{ IPropertyMetaclass 
						- _Name = "Configuration";
						- Properties = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IProperty 
								- _Name = "MarkPrologEpilogInAnnotations";
								- _Value = "None";
								- _Type = Enum;
								- _ExtraTypeInfo = "None, Ignore, Auto";
							}
						}
					}
					{ IPropertyMetaclass 
						- _Name = "Dependency";
						- Properties = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IProperty 
								- _Name = "MarkPrologEpilogInAnnotations";
								- _Value = "None";
								- _Type = Enum;
								- _ExtraTypeInfo = "None, Ignore, Auto";
							}
						}
					}
					{ IPropertyMetaclass 
						- _Name = "Operation";
						- Properties = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IProperty 
								- _Name = "MarkPrologEpilogInAnnotations";
								- _Value = "None";
								- _Type = Enum;
								- _ExtraTypeInfo = "None, Ignore, Auto";
							}
						}
					}
					{ IPropertyMetaclass 
						- _Name = "Package";
						- Properties = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IProperty 
								- _Name = "MarkPrologEpilogInAnnotations";
								- _Value = "None";
								- _Type = Enum;
								- _ExtraTypeInfo = "None, Ignore, Auto";
							}
						}
					}
				}
			}
			{ IPropertySubject 
				- _Name = "SequenceDiagram";
				- Metaclasses = { IRPYRawContainer 
					- size = 2;
					- value = 
					{ IPropertyMetaclass 
						- _Name = "General";
						- Properties = { IRPYRawContainer 
							- size = 3;
							- value = 
							{ IProperty 
								- _Name = "ClassCentricMode";
								- _Value = "True";
								- _Type = Bool;
							}
							{ IProperty 
								- _Name = "CleanupRealized";
								- _Value = "True";
								- _Type = Bool;
							}
							{ IProperty 
								- _Name = "RealizeMessages";
								- _Value = "True";
								- _Type = Bool;
							}
						}
					}
					{ IPropertyMetaclass 
						- _Name = "InstanceLine";
						- Properties = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IProperty 
								- _Name = "spacing_units";
								- _Value = "3";
								- _Type = Int;
							}
						}
					}
				}
			}
		}
	}
	- _name = "Avionics_6";
	- _lastID = 3;
	- _UserColors = { IRPYRawContainer 
		- size = 16;
		- value = 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 
	}
	- _defaultSubsystem = { ISubsystemHandle 
		- _m2Class = "ISubsystem";
		- _filename = "Prototype.sbs";
		- _subsystem = "";
		- _class = "";
		- _name = "Prototype";
		- _id = GUID 87d3fdb2-70de-4bb3-a8a9-e998cf9bc9b5;
	}
	- _component = { IHandle 
		- _m2Class = "IComponent";
		- _filename = "DefaultComponent.cmp";
		- _subsystem = "";
		- _class = "";
		- _name = "DefaultComponent";
		- _id = GUID c13b2e42-2888-44b8-a1e1-99224ceb536e;
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
		- size = 14;
		- value = 
		{ ISubsystem 
			- fileName = "Prototype";
			- _id = GUID 87d3fdb2-70de-4bb3-a8a9-e998cf9bc9b5;
		}
		{ ISubsystem 
			- fileName = "AirframePkg";
			- _id = GUID 718c6e07-37b5-4bc4-b24a-1a6ac6912471;
		}
		{ ISubsystem 
			- fileName = "AutopilotPkg";
			- _id = GUID c9142634-dee8-4f23-9ab2-94629976d079;
		}
		{ ISubsystem 
			- fileName = "DisplayPkg";
			- _id = GUID 1f4df77a-ce15-4b4b-9f30-a2b94de5daf8;
		}
		{ ISubsystem 
			- fileName = "GuidancePkg";
			- _id = GUID 48747585-d7db-4893-aea1-35e124e95403;
		}
		{ ISubsystem 
			- fileName = "LibraryPkg";
			- _id = GUID f7ea1d29-db32-4756-bf15-fef5352c82ba;
		}
		{ ISubsystem 
			- fileName = "RequirementClasses";
			- _id = GUID f2460322-6b82-11d7-b382-00c04f680d9d;
		}
		{ ISubsystem 
			- fileName = "TargetPkg";
			- _id = GUID 9d763caf-f44a-4d2e-82ea-44a15b60ea2a;
		}
		{ ISubsystem 
			- fileName = "TrackingSubsystemPkg";
			- _id = GUID 48655bb2-120d-40c8-b6b2-5fbfff52ea49;
		}
		{ ISubsystem 
			- fileName = "ReverseEngineering";
			- _id = GUID 782bd0ad-c4cc-4f94-8e3f-11bf56156b2f;
		}
		{ ISubsystem 
			- fileName = "RT_Environment";
			- _id = GUID c123d7ab-34dd-4221-b21f-edfa14ce93c7;
		}
		{ ISubsystem 
			- fileName = "Control_Software";
			- _id = GUID 4430277f-f52e-4b69-84fb-15b14461ceb7;
		}
		{ ISubsystem 
			- fileName = "Device_Interfaces";
			- _id = GUID 5f3609d1-5804-4b8d-8015-bcc8f6dfe56e;
		}
		{ ISubsystem 
			- fileName = "Physical_Environment";
			- _id = GUID d2283d97-9ead-42f6-8004-f4bd40fc7c8b;
		}
	}
	- Diagrams = { IRPYRawContainer 
		- size = 2;
		- value = 
		{ IDiagram 
			- fileName = "AutopilotModels";
			- _id = GUID 6fe1d6f7-34ea-448f-a3a7-9df64c9c5b42;
		}
		{ IDiagram 
			- fileName = "Dynamics";
			- _id = GUID f3ae1da0-6239-4c40-b5fa-6141b84d7a54;
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
			- _id = GUID c13b2e42-2888-44b8-a1e1-99224ceb536e;
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


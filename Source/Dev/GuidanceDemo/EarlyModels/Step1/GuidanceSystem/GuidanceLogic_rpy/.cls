I-Logix-RPY-Archive version 4.0.4 C++
{ IClass 
	- _id = GUID 7d4aa64f-49d9-483d-b075-ea956a327099;
	- _myState = 8192;
	- _properties = { IPropertyContainer 
		- Subjects = { IRPYRawContainer 
			- size = 1;
			- value = 
			{ IPropertySubject 
				- _Name = "CG";
				- Metaclasses = { IRPYRawContainer 
					- size = 1;
					- value = 
					{ IPropertyMetaclass 
						- _Name = "Class";
						- Properties = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IProperty 
								- _Name = "UseAsExternal";
								- _Value = "True";
								- _Type = Bool;
							}
						}
					}
				}
			}
		}
	}
	- _name = "OnAirFrameAutoPilotTest";
	- weakCGTime = 12.9.2002::13:14:3;
	- strongCGTime = 1.2.1990::0:0:0;
	- _multiplicity = "";
	- _hotLink = "";
	- _itsStateChart = NULL;
	- Links = { IRPYRawContainer 
		- size = 0;
	}
	- PrimitiveOperations = { IRPYRawContainer 
		- size = 0;
	}
	- TriggeredOperations = { IRPYRawContainer 
		- size = 0;
	}
	- EventHandles = { IRPYRawContainer 
		- size = 0;
	}
	- Attrs = { IRPYRawContainer 
		- size = 0;
	}
	- Components = { IRPYRawContainer 
		- size = 0;
	}
	- Inheritances = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ IGeneralization 
			- _id = GUID 56a42d2a-2494-4d7f-a0a7-4a341d83e0ec;
			- _dependsOn = { INObjectHandle 
				- _m2Class = "IClass";
				- _filename = "ReverseEngineering.sbs";
				- _subsystem = "ReverseEngineering";
				- _class = "";
				- _name = "OnModel_OnAirFrameAutoPilotTest";
				- _id = GUID 5942c971-1d30-429c-b995-a5c9a7ee2587;
			}
			- _inheritanceType = iPublic;
			- _isVirtual = 0;
		}
	}
	- _classModifier = Unspecified;
}


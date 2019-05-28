I-Logix-RPY-Archive version 4.0.4 C++
{ IClass 
	- _id = GUID 54521690-143c-4de7-9982-8ff706e602fc;
	- _myState = 8192;
	- _properties = { IPropertyContainer 
		- Subjects = { IRPYRawContainer 
			- size = 2;
			- value = 
			{ IPropertySubject 
				- _Name = "CPP_CG";
				- Metaclasses = { IRPYRawContainer 
					- size = 1;
					- value = 
					{ IPropertyMetaclass 
						- _Name = "Class";
						- Properties = { IRPYRawContainer 
							- size = 3;
							- value = 
							{ IProperty 
								- _Name = "AdditionalBaseClasses";
								- _Value = "";
								- _Type = String;
							}
							{ IProperty 
								- _Name = "ImpIncludes";
								- _Value = "EventBroadcast.h, OnDataCollector.h, ShiftLever.h, Clutch.h, Actuator.h, CFrame.h, Band_Brake.h, Ravigneaux.h, Brakes.h, Oneway_Clutch.h, Torque_Converter.h, Chart.h, Engine.h, Vehicle5.h, Throttle.h, Controller.h, TestDrivetrain01.h, TestDrivetrainSS.h";
								- _Type = String;
							}
							{ IProperty 
								- _Name = "SpecIncludes";
								- _Value = "OnUMLEso.h, fstream.h";
								- _Type = String;
							}
						}
					}
				}
			}
			{ IPropertySubject 
				- _Name = "Simulation";
				- Metaclasses = { IRPYRawContainer 
					- size = 1;
					- value = 
					{ IPropertyMetaclass 
						- _Name = "Class";
						- Properties = { IRPYRawContainer 
							- size = 5;
							- value = 
							{ IProperty 
								- _Name = "AttributeOrder";
								- _Value = "task_0100ms";
								- _Type = MultiLine;
							}
							{ IProperty 
								- _Name = "OnCg";
								- _Value = "True";
								- _Type = Bool;
							}
							{ IProperty 
								- _Name = "OperationOrder";
								- _Value = "";
								- _Type = MultiLine;
							}
							{ IProperty 
								- _Name = "SimType";
								- _Value = "Undefined";
								- _Type = Enum;
								- _ExtraTypeInfo = "Undefined,Model,AbstractModel,Connector,Structure,NonSimulation";
							}
							{ IProperty 
								- _Name = "StateOrder";
								- _Value = "";
								- _Type = MultiLine;
							}
						}
					}
				}
			}
		}
	}
	- _name = "TestDrivetrainApp";
	- weakCGTime = 6.27.2003::23:7:14;
	- strongCGTime = 6.27.2003::23:7:14;
	- _multiplicity = "";
	- _hotLink = "";
	- _itsStateChart = NULL;
	- Links = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ ILink 
			- _id = GUID 47b8c7ec-f07c-4a4c-ad3b-adf968c0954b;
			- _properties = { IPropertyContainer 
				- Subjects = { IRPYRawContainer 
					- size = 3;
					- value = 
					{ IPropertySubject 
						- _Name = "CG";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Relation";
								- Properties = { IRPYRawContainer 
									- size = 4;
									- value = 
									{ IProperty 
										- _Name = "AddGenerate";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "ClearGenerate";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "GetGenerate";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SetGenerate";
										- _Value = "False";
										- _Type = Bool;
									}
								}
							}
						}
					}
					{ IPropertySubject 
						- _Name = "CPP_CG";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Relation";
								- Properties = { IRPYRawContainer 
									- size = 1;
									- value = 
									{ IProperty 
										- _Name = "DataMemberVisibility";
										- _Value = "Public";
										- _Type = Enum;
										- _ExtraTypeInfo = "Public, Protected, Private";
									}
								}
							}
						}
					}
					{ IPropertySubject 
						- _Name = "Simulation";
						- Metaclasses = { IRPYRawContainer 
							- size = 2;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Attribute";
								- Properties = { IRPYRawContainer 
									- size = 3;
									- value = 
									{ IProperty 
										- _Name = "Dimension1";
										- _Value = "2";
										- _Type = String;
									}
									{ IProperty 
										- _Name = "Dimension2";
										- _Value = "2";
										- _Type = String;
									}
									{ IProperty 
										- _Name = "OnCg";
										- _Value = "True";
										- _Type = Bool;
									}
								}
							}
							{ IPropertyMetaclass 
								- _Name = "Relation";
								- Properties = { IRPYRawContainer 
									- size = 4;
									- value = 
									{ IProperty 
										- _Name = "OnCg";
										- _Value = "True";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,Matrix";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Variable";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Variable,Parameter,Connector,Model,Struct,Broadcaster,Listener,DataCollector,Input,Output";
									}
									{ IProperty 
										- _Name = "bSim";
										- _Value = "False";
										- _Type = Bool;
									}
								}
							}
						}
					}
				}
			}
			- _name = "task_0100ms";
			- _multiplicity = "1";
			- _otherClass = { IClassHandle 
				- _m2Class = "IClass";
				- _filename = "Application.sbs";
				- _subsystem = "Application";
				- _class = "";
				- _name = "TestDrivetrainApp_task_0100ms";
				- _id = GUID 15d03c4e-9fc7-4f2f-ab31-9b83a48a14d9;
			}
			- _inverse = { IHandle 
				- _m2Class = "";
			}
			- _linkName = "";
			- _linkType = Aggreg;
		}
	}
	- PrimitiveOperations = { IRPYRawContainer 
		- size = 6;
		- value = 
		{ IConstructor 
			- _id = GUID 70975723-b92a-4e31-9a6c-4830da8c6d36;
			- _properties = { IPropertyContainer 
				- Subjects = { IRPYRawContainer 
					- size = 2;
					- value = 
					{ IPropertySubject 
						- _Name = "CG";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 2;
									- value = 
									{ IProperty 
										- _Name = "Animate";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "AnimateArguments";
										- _Value = "False";
										- _Type = Bool;
									}
								}
							}
						}
					}
					{ IPropertySubject 
						- _Name = "Simulation";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 5;
									- value = 
									{ IProperty 
										- _Name = "AutoDiff";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "DiffType";
										- _Value = "Automatic";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Automatic,Numeric";
									}
									{ IProperty 
										- _Name = "OnCg";
										- _Value = "True";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set";
									}
									{ IProperty 
										- _Name = "bSim";
										- _Value = "False";
										- _Type = Bool;
									}
								}
							}
						}
					}
				}
			}
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 0;
			}
			- _returnType = { IHandle 
				- _m2Class = "";
			}
			- _abstract = 0;
			- _final = 0;
			- _concurrency = Sequential;
			- _protection = iPublic;
			- _static = 0;
			- _constant = 0;
			- _itsBody = { IBody 
				- _bodyData = "
init();";
			}
			- _initializer = "";
		}
		{ IDestructor 
			- _id = GUID c158e2b8-8cbb-44e1-ad3a-636be2a4f6a1;
			- _properties = { IPropertyContainer 
				- Subjects = { IRPYRawContainer 
					- size = 2;
					- value = 
					{ IPropertySubject 
						- _Name = "CG";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 2;
									- value = 
									{ IProperty 
										- _Name = "Animate";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "AnimateArguments";
										- _Value = "False";
										- _Type = Bool;
									}
								}
							}
						}
					}
					{ IPropertySubject 
						- _Name = "Simulation";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 5;
									- value = 
									{ IProperty 
										- _Name = "AutoDiff";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "DiffType";
										- _Value = "Automatic";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Automatic,Numeric";
									}
									{ IProperty 
										- _Name = "OnCg";
										- _Value = "True";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set";
									}
									{ IProperty 
										- _Name = "bSim";
										- _Value = "False";
										- _Type = Bool;
									}
								}
							}
						}
					}
				}
			}
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 0;
			}
			- _returnType = { IHandle 
				- _m2Class = "";
			}
			- _abstract = 0;
			- _final = 0;
			- _concurrency = Sequential;
			- _protection = iPublic;
			- _static = 0;
			- _constant = 0;
			- _itsBody = { IBody 
				- _bodyData = "
clean();";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID 09aa523d-133b-4eb4-ba08-0b1a5d5068e0;
			- _properties = { IPropertyContainer 
				- Subjects = { IRPYRawContainer 
					- size = 2;
					- value = 
					{ IPropertySubject 
						- _Name = "CG";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 2;
									- value = 
									{ IProperty 
										- _Name = "Animate";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "AnimateArguments";
										- _Value = "False";
										- _Type = Bool;
									}
								}
							}
						}
					}
					{ IPropertySubject 
						- _Name = "Simulation";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 5;
									- value = 
									{ IProperty 
										- _Name = "AutoDiff";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "DiffType";
										- _Value = "Automatic";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Automatic,Numeric";
									}
									{ IProperty 
										- _Name = "OnCg";
										- _Value = "True";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set";
									}
									{ IProperty 
										- _Name = "bSim";
										- _Value = "False";
										- _Type = Bool;
									}
								}
							}
						}
					}
				}
			}
			- _name = "setTime";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 1;
				- value = 
				{ IArgument 
					- _id = GUID ea980a86-607c-46a2-8723-064cea738850;
					- _name = "t";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 77964328-ae29-4a2a-a1eb-0519045141a2;
						- _declaration = "const double";
					}
					- _argumentDirection = In;
				}
			}
			- _returnType = { IHandle 
				- _m2Class = "IType";
				- _filename = "PredefinedTypes.sbs";
				- _subsystem = "PredefinedTypes";
				- _class = "";
				- _name = "void";
				- _id = GUID c6b70728-b655-45a0-abb7-8ea5d3da94be;
			}
			- _abstract = 0;
			- _final = 0;
			- _concurrency = Sequential;
			- _protection = iPublic;
			- _static = 0;
			- _constant = 0;
			- _itsBody = { IBody 
				- _bodyData = "
task_0100ms->setTime(t);";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID 40eccdd5-222f-4852-8eb6-18c002981c34;
			- _properties = { IPropertyContainer 
				- Subjects = { IRPYRawContainer 
					- size = 2;
					- value = 
					{ IPropertySubject 
						- _Name = "CG";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 2;
									- value = 
									{ IProperty 
										- _Name = "Animate";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "AnimateArguments";
										- _Value = "False";
										- _Type = Bool;
									}
								}
							}
						}
					}
					{ IPropertySubject 
						- _Name = "Simulation";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 5;
									- value = 
									{ IProperty 
										- _Name = "AutoDiff";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "DiffType";
										- _Value = "Automatic";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Automatic,Numeric";
									}
									{ IProperty 
										- _Name = "OnCg";
										- _Value = "True";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set";
									}
									{ IProperty 
										- _Name = "bSim";
										- _Value = "False";
										- _Type = Bool;
									}
								}
							}
						}
					}
				}
			}
			- _name = "handle_tick";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 0;
			}
			- _returnType = { IHandle 
				- _m2Class = "IType";
				- _filename = "PredefinedTypes.sbs";
				- _subsystem = "PredefinedTypes";
				- _class = "";
				- _name = "void";
				- _id = GUID c6b70728-b655-45a0-abb7-8ea5d3da94be;
			}
			- _abstract = 0;
			- _final = 0;
			- _concurrency = Sequential;
			- _protection = iPublic;
			- _static = 0;
			- _constant = 0;
			- _itsBody = { IBody 
				- _bodyData = "
  task_0100ms->handle_tick();";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID 5bbfc6bb-3a7a-4b04-b82b-7b66f649f65f;
			- _properties = { IPropertyContainer 
				- Subjects = { IRPYRawContainer 
					- size = 2;
					- value = 
					{ IPropertySubject 
						- _Name = "CG";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 2;
									- value = 
									{ IProperty 
										- _Name = "Animate";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "AnimateArguments";
										- _Value = "False";
										- _Type = Bool;
									}
								}
							}
						}
					}
					{ IPropertySubject 
						- _Name = "Simulation";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 5;
									- value = 
									{ IProperty 
										- _Name = "AutoDiff";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "DiffType";
										- _Value = "Automatic";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Automatic,Numeric";
									}
									{ IProperty 
										- _Name = "OnCg";
										- _Value = "True";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set";
									}
									{ IProperty 
										- _Name = "bSim";
										- _Value = "False";
										- _Type = Bool;
									}
								}
							}
						}
					}
				}
			}
			- _name = "init";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 0;
			}
			- _returnType = { IHandle 
				- _m2Class = "IType";
				- _filename = "PredefinedTypes.sbs";
				- _subsystem = "PredefinedTypes";
				- _class = "";
				- _name = "void";
				- _id = GUID c6b70728-b655-45a0-abb7-8ea5d3da94be;
			}
			- _abstract = 0;
			- _final = 0;
			- _concurrency = Sequential;
			- _protection = iPublic;
			- _static = 0;
			- _constant = 0;
			- _itsBody = { IBody 
				- _bodyData = "
task_0100ms = new TestDrivetrainApp_task_0100ms();


// begin broadcaster / handler communication initialization
ONI_BEGIN_BROADCAST_MAP(long)
  ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_EngineStart)
  ONI_OPER_LISTENER_IMPL(
  /* TargetCompositeObject: */ task_0100ms->itsTestDrivetrainSS, 
  /* TargetClass: */ Engine, 
  /* TargetObject: */ task_0100ms->itsTestDrivetrainSS->m_pSystemModel->itsEngine, 
  /* TargetOperation: */ handle_Start)
ONI_END_BROADCAST_MAP()

ONI_BEGIN_BROADCAST_MAP(double)
  ONI_FCN_BROADCASTER_IMPL(
    /* SourceCompositeObject: */ task_0100ms->itsWheelBrake, 
    /* SourceClass: */ Brakes, 
    /* SourceObject: */ task_0100ms->itsWheelBrake, 
    /* SourceFunction: */ getPosition)
  ONI_OPER_LISTENER_IMPL(
  /* TargetCompositeObject: */ task_0100ms->itsTestDrivetrainSS, 
  /* TargetClass: */ Vehicle5, 
  /* TargetObject: */ task_0100ms->itsTestDrivetrainSS->m_pSystemModel->itsVehicle, 
  /* TargetOperation: */ handle_brakePedal)
ONI_END_BROADCAST_MAP()

ONI_BEGIN_BROADCAST_MAP(double)
  ONI_FCN_BROADCASTER_IMPL(
    /* SourceCompositeObject: */ task_0100ms->itsTestDrivetrainSS, 
    /* SourceClass: */ Vehicle5, 
    /* SourceObject: */ task_0100ms->itsTestDrivetrainSS->m_pSystemModel->itsVehicle, 
    /* SourceFunction: */ getSpeed)
  ONI_OPER_LISTENER_IMPL(
  /* TargetCompositeObject: */ task_0100ms->itsSpeedChart, 
  /* TargetClass: */ Chart, 
  /* TargetObject: */ task_0100ms->itsSpeedChart, 
  /* TargetOperation: */ handle_plotData)
  ONI_OPER_LISTENER_IMPL(
  /* TargetCompositeObject: */ task_0100ms->itsShiftController, 
  /* TargetClass: */ Controller, 
  /* TargetObject: */ task_0100ms->itsShiftController, 
  /* TargetOperation: */ handle_SpeedData)
ONI_END_BROADCAST_MAP()

ONI_BEGIN_BROADCAST_MAP(long)
  ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_OB)
  ONI_OPER_LISTENER_IMPL(
  /* TargetCompositeObject: */ task_0100ms->itsTestDrivetrainSS, 
  /* TargetClass: */ Actuator, 
  /* TargetObject: */ task_0100ms->itsTestDrivetrainSS->m_pSystemModel->aOB, 
  /* TargetOperation: */ handle_shiftEvent)
ONI_END_BROADCAST_MAP()

ONI_BEGIN_BROADCAST_MAP(long)
  ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_DC)
  ONI_OPER_LISTENER_IMPL(
  /* TargetCompositeObject: */ task_0100ms->itsTestDrivetrainSS, 
  /* TargetClass: */ Actuator, 
  /* TargetObject: */ task_0100ms->itsTestDrivetrainSS->m_pSystemModel->aDC, 
  /* TargetOperation: */ handle_shiftEvent)
ONI_END_BROADCAST_MAP()

ONI_BEGIN_BROADCAST_MAP(long)
  ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_POC)
  ONI_OPER_LISTENER_IMPL(
  /* TargetCompositeObject: */ task_0100ms->itsTestDrivetrainSS, 
  /* TargetClass: */ Actuator, 
  /* TargetObject: */ task_0100ms->itsTestDrivetrainSS->m_pSystemModel->aPOC, 
  /* TargetOperation: */ handle_shiftEvent)
ONI_END_BROADCAST_MAP()

ONI_BEGIN_BROADCAST_MAP(long)
  ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_FC)
  ONI_OPER_LISTENER_IMPL(
  /* TargetCompositeObject: */ task_0100ms->itsTestDrivetrainSS, 
  /* TargetClass: */ Actuator, 
  /* TargetObject: */ task_0100ms->itsTestDrivetrainSS->m_pSystemModel->aFC, 
  /* TargetOperation: */ handle_shiftEvent)
ONI_END_BROADCAST_MAP()

ONI_BEGIN_BROADCAST_MAP(long)
  ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_LRB)
  ONI_OPER_LISTENER_IMPL(
  /* TargetCompositeObject: */ task_0100ms->itsTestDrivetrainSS, 
  /* TargetClass: */ Actuator, 
  /* TargetObject: */ task_0100ms->itsTestDrivetrainSS->m_pSystemModel->aLRB, 
  /* TargetOperation: */ handle_shiftEvent)
ONI_END_BROADCAST_MAP()

ONI_BEGIN_BROADCAST_MAP(long)
  ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_RC)
  ONI_OPER_LISTENER_IMPL(
  /* TargetCompositeObject: */ task_0100ms->itsTestDrivetrainSS, 
  /* TargetClass: */ Actuator, 
  /* TargetObject: */ task_0100ms->itsTestDrivetrainSS->m_pSystemModel->aRC, 
  /* TargetOperation: */ handle_shiftEvent)
ONI_END_BROADCAST_MAP()

ONI_BEGIN_BROADCAST_MAP(double)
  ONI_FCN_BROADCASTER_IMPL(
    /* SourceCompositeObject: */ task_0100ms->itsTestDrivetrainSS, 
    /* SourceClass: */ Engine, 
    /* SourceObject: */ task_0100ms->itsTestDrivetrainSS->m_pSystemModel->itsEngine, 
    /* SourceFunction: */ getRPM)
  ONI_OPER_LISTENER_IMPL(
  /* TargetCompositeObject: */ task_0100ms->itsEngineChart, 
  /* TargetClass: */ Chart, 
  /* TargetObject: */ task_0100ms->itsEngineChart, 
  /* TargetOperation: */ handle_plotData)
ONI_END_BROADCAST_MAP()

ONI_BEGIN_BROADCAST_MAP(double)
  ONI_FCN_BROADCASTER_IMPL(
    /* SourceCompositeObject: */ task_0100ms->itsThrottle, 
    /* SourceClass: */ Throttle, 
    /* SourceObject: */ task_0100ms->itsThrottle, 
    /* SourceFunction: */ getPosition)
  ONI_OPER_LISTENER_IMPL(
  /* TargetCompositeObject: */ task_0100ms->itsTestDrivetrainSS, 
  /* TargetClass: */ Engine, 
  /* TargetObject: */ task_0100ms->itsTestDrivetrainSS->m_pSystemModel->itsEngine, 
  /* TargetOperation: */ handle_throttle)
  ONI_OPER_LISTENER_IMPL(
  /* TargetCompositeObject: */ task_0100ms->itsShiftController, 
  /* TargetClass: */ Controller, 
  /* TargetObject: */ task_0100ms->itsShiftController, 
  /* TargetOperation: */ handle_ThrottleData)
ONI_END_BROADCAST_MAP()

ONI_BEGIN_BROADCAST_MAP(long)
  ONI_FCN_BROADCASTER_IMPL(
    /* SourceCompositeObject: */ task_0100ms->itsShiftLever, 
    /* SourceClass: */ ShiftLever, 
    /* SourceObject: */ task_0100ms->itsShiftLever, 
    /* SourceFunction: */ get_Position)
  ONI_OPER_LISTENER_IMPL(
  /* TargetCompositeObject: */ task_0100ms->itsShiftController, 
  /* TargetClass: */ Controller, 
  /* TargetObject: */ task_0100ms->itsShiftController, 
  /* TargetOperation: */ handle_ShiftLeverData)
ONI_END_BROADCAST_MAP()

ONI_BEGIN_BROADCAST_MAP(long)
  ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_IOC)
  ONI_OPER_LISTENER_IMPL(
  /* TargetCompositeObject: */ task_0100ms->itsTestDrivetrainSS, 
  /* TargetClass: */ Actuator, 
  /* TargetObject: */ task_0100ms->itsTestDrivetrainSS->m_pSystemModel->aIOC, 
  /* TargetOperation: */ handle_shiftEvent)
ONI_END_BROADCAST_MAP()

// end broadcaster / handler communication initialization

task_0100ms->broadcast();";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID 05f4da12-32d0-4bd3-808d-e70c3e876c4f;
			- _properties = { IPropertyContainer 
				- Subjects = { IRPYRawContainer 
					- size = 2;
					- value = 
					{ IPropertySubject 
						- _Name = "CG";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 2;
									- value = 
									{ IProperty 
										- _Name = "Animate";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "AnimateArguments";
										- _Value = "False";
										- _Type = Bool;
									}
								}
							}
						}
					}
					{ IPropertySubject 
						- _Name = "Simulation";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 5;
									- value = 
									{ IProperty 
										- _Name = "AutoDiff";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "DiffType";
										- _Value = "Automatic";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Automatic,Numeric";
									}
									{ IProperty 
										- _Name = "OnCg";
										- _Value = "True";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set";
									}
									{ IProperty 
										- _Name = "bSim";
										- _Value = "False";
										- _Type = Bool;
									}
								}
							}
						}
					}
				}
			}
			- _name = "clean";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 0;
			}
			- _returnType = { IHandle 
				- _m2Class = "IType";
				- _filename = "PredefinedTypes.sbs";
				- _subsystem = "PredefinedTypes";
				- _class = "";
				- _name = "void";
				- _id = GUID c6b70728-b655-45a0-abb7-8ea5d3da94be;
			}
			- _abstract = 0;
			- _final = 0;
			- _concurrency = Sequential;
			- _protection = iPublic;
			- _static = 0;
			- _constant = 0;
			- _itsBody = { IBody 
				- _bodyData = "
if (task_0100ms)
{
  delete task_0100ms;
  task_0100ms = NULL;
}
";
			}
		}
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
		- size = 0;
	}
	- _classModifier = Unspecified;
}


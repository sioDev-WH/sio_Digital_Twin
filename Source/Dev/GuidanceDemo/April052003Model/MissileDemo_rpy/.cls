I-Logix-RPY-Archive version 4.0.4 C++
{ IClass 
	- _id = GUID 262f7dec-63e1-11d7-b377-00c04f680d9d;
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
								- _Value = "public COnUMLDaeEsoImpl<jjjj>";
								- _Type = String;
							}
							{ IProperty 
								- _Name = "ImpIncludes";
								- _Value = "stdafx.h, OnUMLEso.h";
								- _Type = String;
							}
							{ IProperty 
								- _Name = "SpecIncludes";
								- _Value = "OnUMLDaeEsoImpl.h";
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
								- _Value = "FinLink,BodyLink,AeroLink";
								- _Type = MultiLine;
							}
							{ IProperty 
								- _Name = "OnCg";
								- _Value = "False";
								- _Type = Bool;
							}
							{ IProperty 
								- _Name = "OperationOrder";
								- _Value = "";
								- _Type = MultiLine;
							}
							{ IProperty 
								- _Name = "SimType";
								- _Value = "Model";
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
	- _name = "jjjj";
	- weakCGTime = 3.31.2003::20:32:4;
	- strongCGTime = 3.31.2003::20:32:4;
	- _multiplicity = "";
	- _hotLink = "";
	- _itsStateChart = NULL;
	- Links = { IRPYRawContainer 
		- size = 3;
		- value = 
		{ ILink 
			- _id = GUID 262f7dff-63e1-11d7-b377-00c04f680d9d;
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
										- _Value = "Model";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Variable,Parameter,Connector,Model,Struct,Broadcaster,Listener,DataCollector,Input,Output";
									}
									{ IProperty 
										- _Name = "bSim";
										- _Value = "True";
										- _Type = Bool;
									}
								}
							}
						}
					}
				}
			}
			- _name = "FinLink";
			- _multiplicity = "1";
			- _otherClass = { IClassHandle 
				- _m2Class = "IClass";
				- _filename = "AirframePkg.sbs";
				- _subsystem = "AirframePkg";
				- _class = "";
				- _name = "FinActuator";
				- _id = GUID 07a2767e-6557-4476-8be3-4b2e1b59c601;
			}
			- _inverse = { IHandle 
				- _m2Class = "";
			}
			- _linkName = "";
			- _linkType = Aggreg;
		}
		{ ILink 
			- _id = GUID 262f7e3a-63e1-11d7-b377-00c04f680d9d;
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
										- _Value = "Model";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Variable,Parameter,Connector,Model,Struct,Broadcaster,Listener,DataCollector,Input,Output";
									}
									{ IProperty 
										- _Name = "bSim";
										- _Value = "True";
										- _Type = Bool;
									}
								}
							}
						}
					}
				}
			}
			- _name = "BodyLink";
			- _multiplicity = "1";
			- _otherClass = { IClassHandle 
				- _m2Class = "IClass";
				- _filename = "AirframePkg.sbs";
				- _subsystem = "AirframePkg";
				- _class = "";
				- _name = "BodyDynamics";
				- _id = GUID f19a6fbd-82a5-4b21-b74e-9664cad3b783;
			}
			- _inverse = { IHandle 
				- _m2Class = "";
			}
			- _linkName = "";
			- _linkType = Aggreg;
		}
		{ ILink 
			- _id = GUID 262f7e75-63e1-11d7-b377-00c04f680d9d;
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
										- _Value = "Model";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Variable,Parameter,Connector,Model,Struct,Broadcaster,Listener,DataCollector,Input,Output";
									}
									{ IProperty 
										- _Name = "bSim";
										- _Value = "True";
										- _Type = Bool;
									}
								}
							}
						}
					}
				}
			}
			- _name = "AeroLink";
			- _multiplicity = "1";
			- _otherClass = { IClassHandle 
				- _m2Class = "IClass";
				- _filename = "AirframePkg.sbs";
				- _subsystem = "AirframePkg";
				- _class = "";
				- _name = "AeroDynamics";
				- _id = GUID 22dfd167-3d2b-43c0-96ac-aee80d530cfb;
			}
			- _inverse = { IHandle 
				- _m2Class = "";
			}
			- _linkName = "";
			- _linkType = Aggreg;
		}
	}
	- PrimitiveOperations = { IRPYRawContainer 
		- size = 8;
		- value = 
		{ IConstructor 
			- _id = GUID 262f7eb1-63e1-11d7-b377-00c04f680d9d;
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
			- _id = GUID 262f7ed3-63e1-11d7-b377-00c04f680d9d;
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
			- _id = GUID 262f7ef6-63e1-11d7-b377-00c04f680d9d;
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
			- _protection = iProtected;
			- _static = 0;
			- _constant = 0;
			- _itsBody = { IBody 
				- _bodyData = "

FinLink = new FinActuator();
FinLink->AddRef();


BodyLink = new BodyDynamics();
BodyLink->AddRef();


AeroLink = new AeroDynamics();
AeroLink->AddRef();

";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID 262f7f1e-63e1-11d7-b377-00c04f680d9d;
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
			- _protection = iProtected;
			- _static = 0;
			- _constant = 0;
			- _itsBody = { IBody 
				- _bodyData = "
if (FinLink)
{
  FinLink->Release();
  FinLink = NULL;
}
if (BodyLink)
{
  BodyLink->Release();
  BodyLink = NULL;
}
if (AeroLink)
{
  AeroLink->Release();
  AeroLink = NULL;
}";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID 262f7f46-63e1-11d7-b377-00c04f680d9d;
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
			- _name = "Save";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 1;
				- value = 
				{ IArgument 
					- _id = GUID 262f7f58-63e1-11d7-b377-00c04f680d9d;
					- _name = "fs";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 262f7f5a-63e1-11d7-b377-00c04f680d9d;
						- _declaration = "FILE*";
					}
					- _argumentDirection = InOut;
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
			- _protection = iProtected;
			- _static = 0;
			- _constant = 0;
			- _itsBody = { IBody 
				- _bodyData = "
FinLink->Save(fs);
BodyLink->Save(fs);
AeroLink->Save(fs);";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID 262f7f71-63e1-11d7-b377-00c04f680d9d;
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
			- _name = "Load";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 1;
				- value = 
				{ IArgument 
					- _id = GUID 262f7f84-63e1-11d7-b377-00c04f680d9d;
					- _name = "fs";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 262f7f86-63e1-11d7-b377-00c04f680d9d;
						- _declaration = "FILE*";
					}
					- _argumentDirection = InOut;
				}
			}
			- myReturnType = { IType 
				- _id = GUID 262f7f7b-63e1-11d7-b377-00c04f680d9d;
				- _declaration = "bool";
			}
			- _abstract = 0;
			- _final = 0;
			- _concurrency = Sequential;
			- _protection = iProtected;
			- _static = 0;
			- _constant = 0;
			- _itsBody = { IBody 
				- _bodyData = "
if (! FinLink->Load(fs) ) return false;
if (! BodyLink->Load(fs) ) return false;
if (! AeroLink->Load(fs) ) return false;

return true;";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID 262f7f9d-63e1-11d7-b377-00c04f680d9d;
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
			- _name = "GetAssociations";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 3;
				- value = 
				{ IArgument 
					- _id = GUID 262f7fb0-63e1-11d7-b377-00c04f680d9d;
					- _name = "Assoc";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 262f7fb2-63e1-11d7-b377-00c04f680d9d;
						- _declaration = "long**";
					}
					- _argumentDirection = InOut;
				}
				{ IArgument 
					- _id = GUID 262f7fb3-63e1-11d7-b377-00c04f680d9d;
					- _name = "Size";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 262f7fb6-63e1-11d7-b377-00c04f680d9d;
						- _declaration = "long**";
					}
					- _argumentDirection = InOut;
				}
				{ IArgument 
					- _id = GUID 262f7fb7-63e1-11d7-b377-00c04f680d9d;
					- _name = "nSize";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 262f7fbb-63e1-11d7-b377-00c04f680d9d;
						- _declaration = "long*";
					}
					- _argumentDirection = InOut;
				}
			}
			- myReturnType = { IType 
				- _id = GUID 262f7fa7-63e1-11d7-b377-00c04f680d9d;
				- _declaration = "HRESULT";
			}
			- _abstract = 0;
			- _final = 0;
			- _concurrency = Sequential;
			- _protection = iProtected;
			- _static = 0;
			- _constant = 0;
			- _itsBody = { IBody 
				- _bodyData = "
long nAssoc;
long i;

const long assoc[] =
{
  2, 1,      0, 0,
  1, 0,      2, 0,
};

const long size[] =
{
  2, 2,
  2, 2,
};

*nSize = sizeof(size) / sizeof(long);
nAssoc = sizeof(assoc) / sizeof(long);

*Size = new long[*nSize];
*Assoc = new long[nAssoc];

for (i = 0; i < *nSize; i++) (*Size)[i] = size[i];
for (i = 0; i < nAssoc; i++) (*Assoc)[i] = assoc[i];

return S_OK;";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID 262f7fd2-63e1-11d7-b377-00c04f680d9d;
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
			- _name = "InitEsos";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 0;
			}
			- myReturnType = { IType 
				- _id = GUID 262f7fdc-63e1-11d7-b377-00c04f680d9d;
				- _declaration = "HRESULT";
			}
			- _abstract = 0;
			- _final = 0;
			- _concurrency = Sequential;
			- _protection = iProtected;
			- _static = 0;
			- _constant = 0;
			- _itsBody = { IBody 
				- _bodyData = "
  ADD_LOCAL_ESO(FinLink)
  ADD_LOCAL_ESO(BodyLink)
  ADD_LOCAL_ESO(AeroLink)

  return S_OK;";
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


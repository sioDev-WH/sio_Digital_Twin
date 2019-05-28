I-Logix-RPY-Archive version 4.0.4 C++
{ IClass 
	- _id = GUID f06876f0-cf8c-4e53-ad78-afab1a359910;
	- _myState = 8192;
	- _properties = { IPropertyContainer 
		- Subjects = { IRPYRawContainer 
			- size = 3;
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
								- _Value = "public COnUMLDaeEsoImpl<aeroFrame>";
								- _Type = String;
							}
							{ IProperty 
								- _Name = "ImpIncludes";
								- _Value = "";
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
				- _Name = "ShapeDefinitions";
				- Metaclasses = { IRPYRawContainer 
					- size = 1;
					- value = 
					{ IPropertyMetaclass 
						- _Name = "Class";
						- Properties = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IProperty 
								- _Name = "UDIDefCollection";
								- _Value = "<UDIDef Name=\"72540327EE3D4BD9BDA308B83F190845\" ClassName=\"aeroFrame\" ID=\"GUID f06876f0-cf8c-4e53-ad78-afab1a359910\" TS=\"100\" Library=\"Avionics.cgl\" Folder=\"Physical\" Shape=\"aeroFrameBlock\" ShapeID=\"6\" >
<CgAttribute Name=\"p\" sType=\"3\" sSubType=\"1\" dim1=\"0\" dim2=\"0\" Value=\"\" bSim=\"True\" />
<CgAttribute Name=\"ph\" sType=\"3\" sSubType=\"1\" dim1=\"0\" dim2=\"0\" Value=\"\" bSim=\"True\" />
<CgAttribute Name=\"gravity\" sType=\"2\" sSubType=\"1\" dim1=\"0\" dim2=\"0\" Value=\"\" bSim=\"True\" />
<CgAttribute Name=\"mass\" sType=\"2\" sSubType=\"1\" dim1=\"0\" dim2=\"0\" Value=\"\" bSim=\"True\" />
<CgConnectionDef Name=\"p\" ItemType=\"1\" ItemID=\"GUID fffe174b-facd-4b86-bd40-f8645bd1de8b\" AttrType=\"3\" OperType=\"0\" ConnName=\"p\" ItemSizeName=\"0\" UserID=\"11\" />
<CgConnectionDef Name=\"ph\" ItemType=\"1\" ItemID=\"GUID 29fa7944-e026-43cf-9ab0-da6d141dfefe\" AttrType=\"3\" OperType=\"0\" ConnName=\"ph\" ItemSizeName=\"0\" UserID=\"21\" />
</UDIDef>
";
								- _Type = MultiLine;
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
								- _Value = "p,ph,gravity,mass";
								- _Type = MultiLine;
							}
							{ IProperty 
								- _Name = "OnCg";
								- _Value = "False";
								- _Type = Bool;
							}
							{ IProperty 
								- _Name = "OperationOrder";
								- _Value = "aeroFrame,~aeroFrame,init,clean,Save,Load,r_Position,r_Force,r_Moments";
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
	- _name = "aeroFrame";
	- weakCGTime = 10.28.2003::23:31:51;
	- strongCGTime = 10.28.2003::23:31:51;
	- _multiplicity = "";
	- _hotLink = "";
	- _itsStateChart = NULL;
	- Links = { IRPYRawContainer 
		- size = 2;
		- value = 
		{ IClassInstance 
			- _id = GUID fffe174b-facd-4b86-bd40-f8645bd1de8b;
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
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Relation";
								- Properties = { IRPYRawContainer 
									- size = 6;
									- value = 
									{ IProperty 
										- _Name = "Dimension1";
										- _Value = "0";
										- _Type = String;
									}
									{ IProperty 
										- _Name = "Dimension2";
										- _Value = "0";
										- _Type = String;
									}
									{ IProperty 
										- _Name = "OnCg";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,Matrix,valarray";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Connector";
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
			- _name = "p";
			- _multiplicity = "1";
			- _otherClass = { IClassHandle 
				- _m2Class = "IClass";
				- _filename = "AirframePkg.sbs";
				- _subsystem = "AirframePkg";
				- _class = "";
				- _name = "aeroPort";
				- _id = GUID 72439b59-e56a-4bfc-8a4a-8bd28556cecf;
			}
			- _inverse = { IHandle 
				- _m2Class = "";
			}
		}
		{ IClassInstance 
			- _id = GUID 29fa7944-e026-43cf-9ab0-da6d141dfefe;
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
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Relation";
								- Properties = { IRPYRawContainer 
									- size = 6;
									- value = 
									{ IProperty 
										- _Name = "Dimension1";
										- _Value = "0";
										- _Type = String;
									}
									{ IProperty 
										- _Name = "Dimension2";
										- _Value = "0";
										- _Type = String;
									}
									{ IProperty 
										- _Name = "OnCg";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,Matrix,valarray";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Connector";
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
			- _name = "ph";
			- _multiplicity = "1";
			- _otherClass = { IClassHandle 
				- _m2Class = "IClass";
				- _filename = "AirframePkg.sbs";
				- _subsystem = "AirframePkg";
				- _class = "";
				- _name = "AtmoHeightPort";
				- _id = GUID ddf3e2ae-279f-4136-b0ff-35d53c3e1ad5;
			}
			- _inverse = { IHandle 
				- _m2Class = "";
			}
		}
	}
	- PrimitiveOperations = { IRPYRawContainer 
		- size = 20;
		- value = 
		{ IConstructor 
			- _id = GUID aaccc14f-1f8e-4d71-b4cc-425adca096ed;
			- _properties = { IPropertyContainer 
				- Subjects = { IRPYRawContainer 
					- size = 1;
					- value = 
					{ IPropertySubject 
						- _Name = "Simulation";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 6;
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
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
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
				- _bodyData = "init();";
			}
			- _initializer = "";
		}
		{ IDestructor 
			- _id = GUID f67b9f6f-70af-4f41-aff1-18e51f85fe1e;
			- _properties = { IPropertyContainer 
				- Subjects = { IRPYRawContainer 
					- size = 1;
					- value = 
					{ IPropertySubject 
						- _Name = "Simulation";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 6;
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
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
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
			- _virtual = 1;
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
				- _bodyData = "clean();";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID 77dcf1ea-ce42-4fa8-bed5-5e1123a48eb9;
			- _properties = { IPropertyContainer 
				- Subjects = { IRPYRawContainer 
					- size = 1;
					- value = 
					{ IPropertySubject 
						- _Name = "Simulation";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 6;
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
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
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
				- _bodyData = "#define m2ft 3.280840
#define Kg2slug 0.0685218

gravity = 9.81;
mass = 13.98/Kg2slug;

p.velocity[0] = 984.0; // u";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID ea357845-4ef6-4c43-8c4f-45997e595661;
			- _properties = { IPropertyContainer 
				- Subjects = { IRPYRawContainer 
					- size = 1;
					- value = 
					{ IPropertySubject 
						- _Name = "Simulation";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 6;
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
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
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
		}
		{ IPrimitiveOperation 
			- _id = GUID 44d7fb25-23d8-404e-a4cd-0e269394d690;
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
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 2;
									- value = 
									{ IProperty 
										- _Name = "Inline";
										- _Value = "none";
										- _Type = Enum;
										- _ExtraTypeInfo = "none,in_header,in_source,in_declaration";
									}
									{ IProperty 
										- _Name = "Kind";
										- _Value = "common";
										- _Type = Enum;
										- _ExtraTypeInfo = "common,abstract";
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
									- size = 6;
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
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SimSubType";
										- _Value = "valarray";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set";
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
			- _name = "r_Force";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 1;
				- value = 
				{ IArgument 
					- _id = GUID cc8f184d-a90b-4b8e-9702-0095e778f5ff;
					- _name = "res";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 51c173cc-f124-44c8-a92d-c184510e27f9;
						- _declaration = "valarray<double>*";
					}
					- _argumentDirection = In;
				}
			}
			- myReturnType = { IType 
				- _id = GUID cd0c23fc-a9d0-4d30-9c13-fb39b5573787;
				- _declaration = "HRESULT";
			}
			- _abstract = 0;
			- _final = 0;
			- _concurrency = Sequential;
			- _protection = iPublic;
			- _static = 0;
			- _constant = 0;
			- _itsBody = { IBody 
				- _bodyData = "if (res->size() != 3) res->resize(3);

(*res)[0] = p.force[0] + gravity * mass * sin(p.angle[1]);
(*res)[1] = p.force[1];
(*res)[2] = p.force[2] - gravity * mass * cos(p.angle[1]);

return S_OK;";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID fa25c6c7-d8b4-4e98-a331-807009b115b6;
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
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 2;
									- value = 
									{ IProperty 
										- _Name = "Inline";
										- _Value = "none";
										- _Type = Enum;
										- _ExtraTypeInfo = "none,in_header,in_source,in_declaration";
									}
									{ IProperty 
										- _Name = "Kind";
										- _Value = "common";
										- _Type = Enum;
										- _ExtraTypeInfo = "common,abstract";
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
									- size = 6;
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
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SimSubType";
										- _Value = "valarray";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set";
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
			- _name = "r_Moments";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 1;
				- value = 
				{ IArgument 
					- _id = GUID 851773d7-ef5b-426b-9365-9e604aa9b6e7;
					- _name = "res";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 2410cd73-9f09-4a28-ae71-643f2057f95f;
						- _declaration = "valarray<double>*";
					}
					- _argumentDirection = In;
				}
			}
			- myReturnType = { IType 
				- _id = GUID 464e5d92-f210-4786-b49d-b17a724bff71;
				- _declaration = "HRESULT";
			}
			- _abstract = 0;
			- _final = 0;
			- _concurrency = Sequential;
			- _protection = iPublic;
			- _static = 0;
			- _constant = 0;
			- _itsBody = { IBody 
				- _bodyData = "if (res->size() != 3) res->resize(3);

(*res) = p.moment;

return S_OK;";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID 864c5d93-9e96-490b-83dd-e66fc65c2398;
			- _properties = { IPropertyContainer 
				- Subjects = { IRPYRawContainer 
					- size = 1;
					- value = 
					{ IPropertySubject 
						- _Name = "Simulation";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 6;
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
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set";
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
			- _name = "r_Position";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 1;
				- value = 
				{ IArgument 
					- _id = GUID b7b4f7f1-2d13-4e25-945b-53364b9aa3af;
					- _name = "res";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 5a8ce8e7-c53d-4bfb-ad9e-33abd58ffb98;
						- _declaration = "double * %s";
					}
					- _argumentDirection = In;
				}
			}
			- myReturnType = { IType 
				- _id = GUID 9b8a7b9a-6a87-48a3-b0a0-7f03e2e28bbe;
				- _declaration = "HRESULT";
			}
			- _abstract = 0;
			- _final = 0;
			- _concurrency = Sequential;
			- _protection = iPublic;
			- _static = 0;
			- _constant = 0;
			- _itsBody = { IBody 
				- _bodyData = "*res = ph.height[0] - p.position[2]; 
return S_OK;";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID 324510a7-3fe0-4b77-b1e9-0339a7df4bc0;
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
									- size = 6;
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
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set,ContinuousArray";
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
			- _name = "handle_gravity";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 2;
				- value = 
				{ IArgument 
					- _id = GUID dd1f20ce-0789-4850-9d09-bbe7362f205a;
					- _name = "t";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 6763b0d1-465a-4a5e-890b-76887e8600cb;
						- _declaration = "const double";
					}
					- _argumentDirection = In;
				}
				{ IArgument 
					- _id = GUID 9d10c181-dad3-4d13-856c-a1207237e804;
					- _name = "val";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 79ace0a1-bf2e-4dd4-9063-f6f8f3fca4c9;
						- _declaration = "const double*";
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
PostRealParameter(t, 0, *val);";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID 4c407849-9841-4e30-9362-d23b3bab7199;
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
									- size = 6;
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
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set,ContinuousArray";
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
			- _name = "handle_mass";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 2;
				- value = 
				{ IArgument 
					- _id = GUID c23d08bf-02ef-437e-92f8-e19b3813ac35;
					- _name = "t";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 750870ea-59a9-464a-8bfc-81011a51c6c9;
						- _declaration = "const double";
					}
					- _argumentDirection = In;
				}
				{ IArgument 
					- _id = GUID 5823c796-28e8-4d1e-992c-264b146a3eb3;
					- _name = "val";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID b4b306fe-465c-4791-b28b-7aa3d78ccbb9;
						- _declaration = "const double*";
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
PostRealParameter(t, 1, *val);";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID f7ad9055-4de9-4005-b06e-c505d7ecc6bd;
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
									- size = 6;
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
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set,ContinuousArray";
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
			- _name = "InitLocalVars";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 3;
				- value = 
				{ IArgument 
					- _id = GUID 4656a7f3-f93c-4ed5-b656-a87f61259e7d;
					- _name = "prefix";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 4abf177a-6f84-4b26-800b-23473dd83b52;
						- _declaration = "const _TCHAR*";
					}
					- _argumentDirection = In;
				}
				{ IArgument 
					- _id = GUID acaad496-882b-45f1-97ec-0450f5f742cb;
					- _name = "varC";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 07d6021e-343e-4304-a6e4-5e822c8885c3;
						- _declaration = "VarCont*";
					}
					- _argumentDirection = InOut;
				}
				{ IArgument 
					- _id = GUID a1cb4044-b98f-49ac-8592-48ab252af906;
					- _name = "bADOnly";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 10f42fe2-6375-4132-a147-56ab4e4eeba9;
						- _declaration = "const bool";
					}
					- _argumentDirection = In;
				}
			}
			- myReturnType = { IType 
				- _id = GUID b9618b69-3707-4f38-a319-05197cd1d068;
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


for (long i = 0; i < m_nEsos; i++)
  AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID d8563216-a16a-4b57-bf9a-b8ce8951500c;
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
									- size = 6;
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
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set,ContinuousArray";
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
			- _name = "InitLocalRPars";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 5;
				- value = 
				{ IArgument 
					- _id = GUID e1baacdf-551a-425e-a8a4-de2782cb625d;
					- _name = "prefix";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 1408ede3-84ac-4b37-a9a6-793e14617d56;
						- _declaration = "const _TCHAR*";
					}
					- _argumentDirection = In;
				}
				{ IArgument 
					- _id = GUID 33b4f185-7562-4a03-a6b1-244e5ecb79a0;
					- _name = "pars";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID b3901204-d625-4cf5-b52b-732516ac9699;
						- _declaration = "ppdouble*";
					}
					- _argumentDirection = InOut;
				}
				{ IArgument 
					- _id = GUID 631d3510-7a51-4b02-bd9d-b77f0e95d739;
					- _name = "Names";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID c27844e3-a2e1-46eb-be6a-3b849415e614;
						- _declaration = "ppchar*";
					}
					- _argumentDirection = InOut;
				}
				{ IArgument 
					- _id = GUID 31dc6040-ea12-49ae-b06a-3decc30012dc;
					- _name = "nPars";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID d39c0e4b-2b94-431e-8d1f-f8963844430b;
						- _declaration = "long*";
					}
					- _argumentDirection = InOut;
				}
				{ IArgument 
					- _id = GUID fb7e678d-afe9-4766-9ffb-de49740d436c;
					- _name = "dPars";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 2dee84d6-526e-4967-a5a1-a4b5e7f00e77;
						- _declaration = "long*";
					}
					- _argumentDirection = InOut;
				}
			}
			- myReturnType = { IType 
				- _id = GUID 16a03a22-ef49-4603-9b6d-95996e0a1173;
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

  ADD_LOCAL_SRPAR(gravity)
  ADD_LOCAL_SRPAR(mass)

  return S_OK;";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID f4444a64-186c-42cf-86c8-a619f8054050;
			- _properties = { IPropertyContainer 
				- Subjects = { IRPYRawContainer 
					- size = 1;
					- value = 
					{ IPropertySubject 
						- _Name = "Simulation";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 6;
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
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set,ContinuousArray";
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
					- _id = GUID 72ab6862-f186-49b6-8970-372bec6e3e10;
					- _name = "fs";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID c672b431-1506-4034-ba19-184d67528bfe;
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
			- _protection = iPublic;
			- _static = 0;
			- _constant = 0;
			- _itsBody = { IBody 
				- _bodyData = "";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID b367677c-389e-4bae-9de0-a4b7a0f58667;
			- _properties = { IPropertyContainer 
				- Subjects = { IRPYRawContainer 
					- size = 1;
					- value = 
					{ IPropertySubject 
						- _Name = "Simulation";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 6;
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
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set,ContinuousArray";
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
					- _id = GUID 0d760f74-5b52-4893-840f-5d98b6d730b7;
					- _name = "fs";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 6f190739-049e-4afe-b95f-0ce73b0c341a;
						- _declaration = "FILE*";
					}
					- _argumentDirection = InOut;
				}
			}
			- myReturnType = { IType 
				- _id = GUID 5ba7ed83-4d90-4505-8e60-8028973b03b9;
				- _declaration = "bool";
			}
			- _abstract = 0;
			- _final = 0;
			- _concurrency = Sequential;
			- _protection = iPublic;
			- _static = 0;
			- _constant = 0;
			- _itsBody = { IBody 
				- _bodyData = "
return true;";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID d4fd252a-5451-4d1f-b290-6d1ce48ae1fa;
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
									- size = 6;
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
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set,ContinuousArray";
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
				- _id = GUID 653383cc-152b-43b7-a82d-67dc2400b064;
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
  ADD_LOCAL_ESO(&p)
  ADD_LOCAL_ESO(&ph)

  return S_OK;";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID 086b048b-23ab-4043-b097-6d241b1f1b5d;
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
						- _Name = "CPP_CG";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 2;
									- value = 
									{ IProperty 
										- _Name = "Inline";
										- _Value = "none";
										- _Type = Enum;
										- _ExtraTypeInfo = "none,in_header,in_source,in_declaration";
									}
									{ IProperty 
										- _Name = "Kind";
										- _Value = "common";
										- _Type = Enum;
										- _ExtraTypeInfo = "common,abstract";
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
									- size = 6;
									- value = 
									{ IProperty 
										- _Name = "AutoDiff";
										- _Value = "True";
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
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set,ContinuousArray";
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
			- _name = "ad_r_Force";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 1;
				- value = 
				{ IArgument 
					- _id = GUID 65b4d373-4e94-460e-89a4-22b87c5e221c;
					- _name = "res";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID d87ee909-ee76-42d1-a524-56b8b763fb17;
						- _declaration = "valarray<Fdouble>*";
					}
					- _argumentDirection = InOut;
				}
			}
			- myReturnType = { IType 
				- _id = GUID 48331953-f3d3-4a82-ba31-c99965f7781f;
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
if (res->size() != 3) res->resize(3);

(*res)[0] = p.AD(force)[0] + gravity * mass * sin(p.AD(angle)[1]);
(*res)[1] = p.AD(force)[1];
(*res)[2] = p.AD(force)[2] - gravity * mass * cos(p.AD(angle)[1]);

return S_OK;
";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID 3a290947-7f37-43b6-9c66-48694d841d9a;
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
						- _Name = "CPP_CG";
						- Metaclasses = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Operation";
								- Properties = { IRPYRawContainer 
									- size = 2;
									- value = 
									{ IProperty 
										- _Name = "Inline";
										- _Value = "none";
										- _Type = Enum;
										- _ExtraTypeInfo = "none,in_header,in_source,in_declaration";
									}
									{ IProperty 
										- _Name = "Kind";
										- _Value = "common";
										- _Type = Enum;
										- _ExtraTypeInfo = "common,abstract";
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
									- size = 6;
									- value = 
									{ IProperty 
										- _Name = "AutoDiff";
										- _Value = "True";
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
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set,ContinuousArray";
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
			- _name = "ad_r_Moments";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 1;
				- value = 
				{ IArgument 
					- _id = GUID 123aa1f7-9cbf-463f-8844-db65fa375d92;
					- _name = "res";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID 89afbc17-634c-4afc-a266-83b7c100f662;
						- _declaration = "valarray<Fdouble>*";
					}
					- _argumentDirection = InOut;
				}
			}
			- myReturnType = { IType 
				- _id = GUID 7d84bf2a-6d94-4e9d-bdaa-a6c71ec85d76;
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
if (res->size() != 3) res->resize(3);

(*res) = p.AD(moment);

return S_OK;
";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID 3c646a89-ddb1-442c-9111-e7b0873f20cc;
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
									- size = 6;
									- value = 
									{ IProperty 
										- _Name = "AutoDiff";
										- _Value = "True";
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
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set,ContinuousArray";
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
			- _name = "ad_r_Position";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 1;
				- value = 
				{ IArgument 
					- _id = GUID ff1ca2dd-68eb-450e-b8ec-8467552a957c;
					- _name = "res";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID ff4baf76-4944-472b-b8a3-b4766e67da8d;
						- _declaration = "Fdouble*";
					}
					- _argumentDirection = InOut;
				}
			}
			- myReturnType = { IType 
				- _id = GUID 48c1eb63-5e2e-4730-a834-b28e85a89a4b;
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
*res = ph.AD(height)[0] - p.AD(position)[2]; 
return S_OK;
";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID c00df563-3a55-4c64-8a7e-18eda5c0d654;
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
									- size = 6;
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
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set,ContinuousArray";
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
			- _name = "InitLocalEqns";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 0;
			}
			- myReturnType = { IType 
				- _id = GUID b80a0579-f6a5-4885-b273-4a138312bcd1;
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
  ADD_LOCAL_EQN(aeroFrame, r_Position)
  ADD_LOCAL_STL_EQN(aeroFrame, r_Force, 1)
  ADD_LOCAL_STL_EQN(aeroFrame, r_Moments, 1)

  return S_OK;";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID b8f7f679-1bcf-4d66-a7c8-4de0f7c58b74;
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
									- size = 6;
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
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set,ContinuousArray";
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
			- _name = "InitLocalADEqns";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 0;
			}
			- myReturnType = { IType 
				- _id = GUID 2820850d-d638-4534-808c-ef949860e7b7;
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
  ADD_LOCAL_AD_EQN(aeroFrame, ad_r_Position)
  ADD_LOCAL_STL_AD_EQN(aeroFrame, ad_r_Force, 1)
  ADD_LOCAL_STL_AD_EQN(aeroFrame, ad_r_Moments, 1)

  return S_OK;";
			}
		}
		{ IPrimitiveOperation 
			- _id = GUID 45842113-9760-4753-859d-517b7f0024fd;
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
									- size = 6;
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
										- _Name = "SimSubType";
										- _Value = "Scalar";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Scalar,Array,valarray,Distributed";
									}
									{ IProperty 
										- _Name = "SimType";
										- _Value = "Continuous";
										- _Type = Enum;
										- _ExtraTypeInfo = "Undefined,Continuous,Discontinuous,Reset,Get,Set,ContinuousArray";
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
			- _name = "InitEqnForm";
			- _virtual = 0;
			- Args = { IRPYRawContainer 
				- size = 2;
				- value = 
				{ IArgument 
					- _id = GUID f72e6cb5-425e-457b-b024-75404fd72976;
					- _name = "form";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID ec82ccd1-7aa5-4c3e-bf67-34aabdeff771;
						- _declaration = "OnEqnForm**";
					}
					- _argumentDirection = InOut;
				}
				{ IArgument 
					- _id = GUID c8e6935e-07e3-4b1e-a41f-7d55573e51a8;
					- _name = "diff_form";
					- _defaultValue = "";
					- myTypeOf = { IType 
						- _id = GUID bb595040-efba-4e96-83d9-7abcd6540f0f;
						- _declaration = "OnEqnDiffForm**";
					}
					- _argumentDirection = InOut;
				}
			}
			- myReturnType = { IType 
				- _id = GUID 3d962bea-f3f8-4556-99e1-d5dbf32ba8d6;
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

const long idx_eqn_r_Position = 0;
const long idx_eqn_r_Force = 1;
const long idx_eqn_r_Moments = 2;

  DESTROY_VECTOR(*form)
  *form = new OnEqnForm[m_nLocalEqns];
  (*form)[idx_eqn_r_Position] = continuous;
  (*form)[idx_eqn_r_Force] = continuous;
  (*form)[idx_eqn_r_Moments] = continuous;

  DESTROY_VECTOR(*diff_form)
  *diff_form = new OnEqnDiffForm[m_nLocalEqns];
  (*diff_form)[idx_eqn_r_Position] = automatic;
  (*diff_form)[idx_eqn_r_Force] = automatic;
  (*diff_form)[idx_eqn_r_Moments] = automatic;

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
		- size = 2;
		- value = 
		{ IAttribute 
			- _id = GUID 299b278c-2203-4002-9b93-784ac2e9ca59;
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
								- _Name = "Attribute";
								- Properties = { IRPYRawContainer 
									- size = 1;
									- value = 
									{ IProperty 
										- _Name = "Visibility";
										- _Value = "protected";
										- _Type = Enum;
										- _ExtraTypeInfo = "private,protected,public,fromAttribute";
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
								- _Name = "Attribute";
								- Properties = { IRPYRawContainer 
									- size = 9;
									- value = 
									{ IProperty 
										- _Name = "AutoDiff";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "Derivative";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "Dimension1";
										- _Value = "0";
										- _Type = String;
									}
									{ IProperty 
										- _Name = "Dimension2";
										- _Value = "0";
										- _Type = String;
									}
									{ IProperty 
										- _Name = "OldValue";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "OnCg";
										- _Value = "False";
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
										- _Value = "Parameter";
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
			- _name = "gravity";
			- _defaultValue = "";
			- _typeOf = { IHandle 
				- _m2Class = "IType";
				- _filename = "PredefinedTypes.sbs";
				- _subsystem = "PredefinedTypes";
				- _class = "";
				- _name = "double";
				- _id = GUID 02ef7294-6849-47b9-9fb2-cfb87b56d2ad;
			}
			- _protection = iPublic;
			- _static = 0;
		}
		{ IAttribute 
			- _id = GUID d0d310fe-30cc-4b05-8129-6da301019c06;
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
								- _Name = "Attribute";
								- Properties = { IRPYRawContainer 
									- size = 1;
									- value = 
									{ IProperty 
										- _Name = "Visibility";
										- _Value = "protected";
										- _Type = Enum;
										- _ExtraTypeInfo = "private,protected,public,fromAttribute";
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
								- _Name = "Attribute";
								- Properties = { IRPYRawContainer 
									- size = 9;
									- value = 
									{ IProperty 
										- _Name = "AutoDiff";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "Derivative";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "Dimension1";
										- _Value = "0";
										- _Type = String;
									}
									{ IProperty 
										- _Name = "Dimension2";
										- _Value = "0";
										- _Type = String;
									}
									{ IProperty 
										- _Name = "OldValue";
										- _Value = "False";
										- _Type = Bool;
									}
									{ IProperty 
										- _Name = "OnCg";
										- _Value = "False";
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
										- _Value = "Parameter";
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
			- _name = "mass";
			- _defaultValue = "";
			- _typeOf = { IHandle 
				- _m2Class = "IType";
				- _filename = "PredefinedTypes.sbs";
				- _subsystem = "PredefinedTypes";
				- _class = "";
				- _name = "double";
				- _id = GUID 02ef7294-6849-47b9-9fb2-cfb87b56d2ad;
			}
			- _protection = iPublic;
			- _static = 0;
		}
	}
	- Components = { IRPYRawContainer 
		- size = 0;
	}
	- Inheritances = { IRPYRawContainer 
		- size = 0;
	}
	- _classModifier = Unspecified;
}


// func cw_msg_ele_discovery_type_test @ 005d0968 size=1472

void cw_msg_ele_discovery_type_test(void)

{
  undefined1 *in_zero;
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 *local_78;
  undefined4 local_74;
  undefined1 auStack_70 [6];
  undefined2 local_6a;
  undefined1 *local_48;
  undefined2 local_44;
  undefined2 local_42;
  
  memset(&local_48,0,0x28);
  memset(auStack_70,0,0x28);
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_78 = (undefined1 *)0x0;
  local_74 = 0;
  *in_zero = 0;
  local_44 = 1;
  local_42 = 0;
  puVar1 = (undefined1 *)FUN_00408450(1,0x41b);
  *puVar1 = 0;
  local_7c = 0x140001;
  *local_48 = 0;
  local_42 = 0;
  iVar2 = (*(code *)PTR_cw_discovery_type_parse_0074c92c)(&local_48,&local_88);
  iVar3 = (*(code *)PTR_cw_discovery_type_create_0074c934)(local_78);
  puts("******clone discovery type start*********");
  (*(code *)PTR_cw_discovery_type_dump_0074c93c)(iVar3);
  puts("*******clone discovery type end**********");
  FUN_00407df0(*(undefined4 *)(iVar3 + 0x10));
  FUN_00407df0(iVar3);
  FUN_00407df0(local_78);
  local_78 = (undefined1 *)0x0;
  if (iVar2 == 0) {
    *local_48 = 1;
    local_42 = 0;
    iVar2 = (*(code *)PTR_cw_discovery_type_parse_0074c92c)(&local_48,&local_88);
    FUN_00407df0(local_78);
    local_78 = (undefined1 *)0x0;
    if (iVar2 == 0) {
      *local_48 = 2;
      local_42 = 0;
      iVar2 = (*(code *)PTR_cw_discovery_type_parse_0074c92c)(&local_48,&local_88);
      FUN_00407df0(local_78);
      local_78 = (undefined1 *)0x0;
      if (iVar2 == 0) {
        *local_48 = 3;
        local_42 = 0;
        iVar2 = (*(code *)PTR_cw_discovery_type_parse_0074c92c)(&local_48,&local_88);
        FUN_00407df0(local_78);
        local_78 = (undefined1 *)0x0;
        if (iVar2 == 0) {
          *local_48 = 4;
          local_42 = 0;
          iVar2 = (*(code *)PTR_cw_discovery_type_parse_0074c92c)(&local_48,&local_88);
          FUN_00407df0(local_78);
          local_78 = (undefined1 *)0x0;
          if (iVar2 == 0) {
            *local_48 = 5;
            local_42 = 0;
            iVar2 = (*(code *)PTR_cw_discovery_type_parse_0074c92c)(&local_48,&local_88);
            if (iVar2 != -1) {
              uVar4 = 0x44e;
              pcVar5 = "UAC_ERROR == ret";
              goto LAB_005d0ba4;
            }
            *puVar1 = 0;
            local_6a = 0;
            local_78 = puVar1;
            iVar2 = (*(code *)PTR_cw_discovery_type_assemble_0074c930)(auStack_70,&local_88);
            if (iVar2 == 0) {
              *puVar1 = 1;
              local_6a = 0;
              iVar2 = (*(code *)PTR_cw_discovery_type_assemble_0074c930)(auStack_70,&local_88);
              if (iVar2 == 0) {
                *puVar1 = 2;
                local_6a = 0;
                iVar2 = (*(code *)PTR_cw_discovery_type_assemble_0074c930)(auStack_70,&local_88);
                if (iVar2 == 0) {
                  *puVar1 = 3;
                  local_6a = 0;
                  iVar2 = (*(code *)PTR_cw_discovery_type_assemble_0074c930)(auStack_70,&local_88);
                  if (iVar2 == 0) {
                    *puVar1 = 4;
                    local_6a = 0;
                    iVar2 = (*(code *)PTR_cw_discovery_type_assemble_0074c930)(auStack_70,&local_88)
                    ;
                    if (iVar2 == 0) {
                      *puVar1 = 5;
                      local_6a = 0;
                      iVar2 = (*(code *)PTR_cw_discovery_type_assemble_0074c930)
                                        (auStack_70,&local_88);
                      if (iVar2 != -1) {
                        uVar4 = 0x46e;
                        pcVar5 = "UAC_ERROR == ret";
                        goto LAB_005d0ba4;
                      }
                      *puVar1 = 0;
                      iVar2 = (*(code *)PTR_cw_discovery_type_dump_0074c93c)(&local_88);
                      if (iVar2 == 0) {
                        *puVar1 = 1;
                        iVar2 = (*(code *)PTR_cw_discovery_type_dump_0074c93c)(&local_88);
                        if (iVar2 == 0) {
                          *puVar1 = 2;
                          iVar2 = (*(code *)PTR_cw_discovery_type_dump_0074c93c)(&local_88);
                          if (iVar2 == 0) {
                            *puVar1 = 3;
                            iVar2 = (*(code *)PTR_cw_discovery_type_dump_0074c93c)(&local_88);
                            if (iVar2 == 0) {
                              *puVar1 = 4;
                              iVar2 = (*(code *)PTR_cw_discovery_type_dump_0074c93c)(&local_88);
                              if (iVar2 == 0) {
                                *puVar1 = 5;
                                iVar2 = (*(code *)PTR_cw_discovery_type_dump_0074c93c)(&local_88);
                                if (iVar2 != -1) {
                                  uVar4 = 0x486;
                                  pcVar5 = "UAC_ERROR == ret";
                                  goto LAB_005d0ba4;
                                }
                                iVar2 = (*(code *)PTR_cw_discovery_type_free_0074c938)(&local_88);
                                if (iVar2 == 0) {
                                  iVar2 = (*(code *)PTR_cw_discovery_type_free_0074c938)(&local_88);
                                  if (iVar2 == 0) {
                                    iVar2 = (*(code *)PTR_cw_discovery_type_free_0074c938)(0);
                                    if (iVar2 == 0) {
                                      return;
                                    }
                                    uVar4 = 0x490;
                                  }
                                  else {
                                    uVar4 = 0x48d;
                                  }
                                }
                                else {
                                  uVar4 = 0x48a;
                                }
                              }
                              else {
                                uVar4 = 0x482;
                              }
                            }
                            else {
                              uVar4 = 0x47e;
                            }
                          }
                          else {
                            uVar4 = 0x47a;
                          }
                        }
                        else {
                          uVar4 = 0x476;
                        }
                      }
                      else {
                        uVar4 = 0x472;
                      }
                    }
                    else {
                      uVar4 = 0x469;
                    }
                  }
                  else {
                    uVar4 = 0x464;
                  }
                }
                else {
                  uVar4 = 0x45f;
                }
              }
              else {
                uVar4 = 0x45a;
              }
            }
            else {
              uVar4 = 0x455;
            }
          }
          else {
            uVar4 = 0x449;
          }
        }
        else {
          uVar4 = 0x442;
        }
      }
      else {
        uVar4 = 0x43b;
      }
    }
    else {
      uVar4 = 0x434;
    }
  }
  else {
    uVar4 = 0x42d;
  }
  pcVar5 = "UAC_OK == ret";
LAB_005d0ba4:
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_msg_ele_discovery_type_test",uVar4,pcVar5);
  return;
}


// func _apdb_parse_linked_modify_items @ 00600634 size=1060

undefined4 _apdb_parse_linked_modify_items(char *param_1,undefined4 *param_2)

{
  char *__s1;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *local_30 [2];
  
  local_30[0] = (char *)0x0;
  if (param_1 == (char *)0x0) {
    uVar2 = 0xffffffff;
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : input string data null.\n",
             "_apdb_parse_linked_modify_items",0x618);
    }
  }
  else {
    memset(param_2,0,0x28);
    __s1 = strtok_r(param_1,",",local_30);
    if (__s1 != (char *)0x0) {
      iVar3 = 10;
      do {
        if (iVar3 == 0) {
          return 0;
        }
        iVar1 = strcmp(__s1,"chnl");
        if (iVar1 == 0) {
          if (apdb_debug_switch != 0) {
            printf("[APDB_DEBUG]%s()/line %d : chnl defined.\n\n","_apdb_parse_linked_modify_items",
                   0x623);
          }
          *param_2 = 1;
        }
        else {
          iVar1 = strcmp(__s1,"rdMd");
          if (iVar1 == 0) {
            if (apdb_debug_switch == 0) {
              param_2[1] = 1;
            }
            else {
              printf("[APDB_DEBUG]%s()/line %d : rdMd defined.\n\n",
                     "_apdb_parse_linked_modify_items",0x627);
              param_2[1] = 1;
            }
          }
          else {
            iVar1 = strcmp(__s1,"bwMd");
            if (iVar1 == 0) {
              if (apdb_debug_switch == 0) {
                param_2[2] = 1;
              }
              else {
                printf("[APDB_DEBUG]%s()/line %d : bwMd defined.\n\n",
                       "_apdb_parse_linked_modify_items",0x62b);
                param_2[2] = 1;
              }
            }
            else {
              iVar1 = strcmp(__s1,"wmm");
              if (iVar1 == 0) {
                if (apdb_debug_switch == 0) {
                  param_2[3] = 1;
                }
                else {
                  printf("[APDB_DEBUG]%s()/line %d : wmm defined.\n\n",
                         "_apdb_parse_linked_modify_items",0x62f);
                  param_2[3] = 1;
                }
              }
              else {
                iVar1 = strcmp(__s1,"brd");
                if (iVar1 == 0) {
                  if (apdb_debug_switch == 0) {
                    param_2[4] = 1;
                  }
                  else {
                    printf("[APDB_DEBUG]%s()/line %d : brd defined.\n\n",
                           "_apdb_parse_linked_modify_items",0x633);
                    param_2[4] = 1;
                  }
                }
                else {
                  iVar1 = strcmp(__s1,"maxUsr");
                  if (iVar1 == 0) {
                    if (apdb_debug_switch == 0) {
                      param_2[5] = 1;
                    }
                    else {
                      printf("[APDB_DEBUG]%s()/line %d : maxUsr defined.\n\n",
                             "_apdb_parse_linked_modify_items",0x637);
                      param_2[5] = 1;
                    }
                  }
                  else {
                    iVar1 = strcmp(__s1,"rssi");
                    if (iVar1 == 0) {
                      if (apdb_debug_switch == 0) {
                        param_2[6] = 1;
                      }
                      else {
                        printf("[APDB_DEBUG]%s()/line %d : rssi defined.\n\n",
                               "_apdb_parse_linked_modify_items",0x63b);
                        param_2[6] = 1;
                      }
                    }
                    else {
                      iVar1 = strcmp(__s1,"dcs");
                      if (iVar1 == 0) {
                        if (apdb_debug_switch == 0) {
                          param_2[7] = 1;
                        }
                        else {
                          printf("[APDB_DEBUG]%s()/line %d : dcs defined.\n\n",
                                 "_apdb_parse_linked_modify_items",0x63f);
                          param_2[7] = 1;
                        }
                      }
                      else {
                        iVar1 = strcmp(__s1,"beacon");
                        if (iVar1 == 0) {
                          if (apdb_debug_switch == 0) {
                            param_2[8] = 1;
                          }
                          else {
                            printf("[APDB_DEBUG]%s()/line %d : beacon interval defined.\n\n",
                                   "_apdb_parse_linked_modify_items",0x643);
                            param_2[8] = 1;
                          }
                        }
                        else {
                          iVar1 = strcmp(__s1,"wlan");
                          if (iVar1 == 0) {
                            if (apdb_debug_switch == 0) {
                              param_2[9] = 1;
                            }
                            else {
                              printf("[APDB_DEBUG]%s()/line %d : wlan_rssi_orient defined.\n\n",
                                     "_apdb_parse_linked_modify_items",0x647);
                              param_2[9] = 1;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        __s1 = strtok_r((char *)0x0,",",local_30);
        iVar3 = iVar3 + -1;
      } while (__s1 != (char *)0x0);
    }
    uVar2 = 0;
  }
  return uVar2;
}


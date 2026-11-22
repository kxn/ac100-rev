// func uac_com_uci_parse_req @ 00514a20 size=2860

undefined4 uac_com_uci_parse_req(int param_1,int param_2,int *param_3,uint param_4)

{
  ushort uVar1;
  char *__s;
  uint uVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  undefined4 *puVar15;
  longlong lVar16;
  undefined8 uVar17;
  undefined1 auStack_60 [16];
  int local_50;
  int local_38;
  int local_34;
  uint local_30;
  
  local_30 = param_4 & 0xff;
  uVar9 = 0xffffffff;
  uVar10 = uVar9;
  if ((((param_1 != 0) && (param_2 != 0)) && (uVar10 = 0xffffffff, param_3 != (int *)0x0)) &&
     (uVar10 = uVar9, local_30 != 0)) {
    local_38 = uci_alloc_context();
    if (local_38 == 0) {
      if (uac_comm_err_switch != 0) {
        printf("[UAC_COMM_ERR]%s()/line %d : alloc uci ctx error\n","uac_com_uci_parse_req",0x6a3);
      }
    }
    else {
      __s = (char *)uac_mem_malloc_my(0x100,0x6a7);
      if (__s == (char *)0x0) {
        if (uac_comm_err_switch != 0) {
          uVar10 = 0x6aa;
          pcVar6 = "[UAC_COMM_ERR]%s()/line %d : malloc error\n";
LAB_00514f44:
          printf(pcVar6,"uac_com_uci_parse_req",uVar10);
        }
LAB_00514b84:
        uVar10 = 0xffffffff;
      }
      else {
        uVar10 = 0xffffffff;
        for (local_34 = 0; local_34 < (int)local_30; local_34 = local_34 + 1) {
          if (local_34 != *param_3) {
            if (uac_comm_err_switch == 0) goto LAB_00514b84;
            uVar10 = 0x6b4;
            pcVar6 = "[UAC_COMM_ERR]%s()/line %d : idx not valid, should be array index.\n";
            goto LAB_00514f44;
          }
          iVar8 = param_3[1];
          if (((iVar8 == 0) || (param_3[7] == 0)) ||
             ((uVar2 = param_3[2], 5 < uVar2 ||
              ((*(short *)(param_3 + 6) == 0 || (*(short *)((int)param_3 + 0x1a) == 0)))))) {
            if (uac_comm_err_switch == 0) goto LAB_00514b84;
            uVar10 = 0x6bb;
            pcVar6 = "[UAC_COMM_ERR]%s()/line %d : paras not valid\n";
            goto LAB_00514f44;
          }
          if (uVar2 == 2) {
LAB_00514cac:
            if (param_3[5] != 0) {
              if (uac_comm_err_switch != 0) {
                uVar10 = 0x632;
                pcVar6 = "_uac_com_uci_float_prase";
LAB_00514d0c:
                printf("[UAC_COMM_ERR]%s()/line %d : not necessary paras specified.\n",pcVar6,uVar10
                      );
              }
              goto LAB_00514b84;
            }
            param_3[8] = 0;
            sprintf(__s,"%s.%s.%s",param_1,param_2,iVar8);
            iVar3 = uci_lookup_ptr(local_38,auStack_60,__s,1);
            iVar8 = local_50;
            if (iVar3 != 0) {
              iVar8 = param_3[3];
LAB_00514fd8:
              if (iVar8 == 0) goto LAB_00514f10;
              if (uac_comm_err_switch != 0) {
                uVar10 = 0x641;
                iVar8 = param_3[1];
                pcVar6 = 
                "[UAC_COMM_ERR]%s()/line %d : not_null option[%s] not found or type mismatch\n";
                pcVar7 = "_uac_com_uci_float_prase";
                goto LAB_005150cc;
              }
              goto LAB_00514b84;
            }
            if (local_50 == 0) {
              iVar8 = param_3[3];
              goto LAB_00514fd8;
            }
            if (*(int *)(local_50 + 0x14) == 0) {
              iVar14 = param_3[2];
              if (iVar14 == 5) {
                iVar8 = param_3[3];
                goto LAB_00514fd8;
              }
              iVar3 = param_3[2];
            }
            else {
              iVar14 = 1;
              iVar3 = param_3[2];
              if (*(int *)(local_50 + 0x14) == 1) {
                if (iVar3 == 2) {
                  iVar8 = param_3[3];
                  goto LAB_00514fd8;
                }
                iVar3 = param_3[2];
              }
            }
            if (iVar3 == 2) {
              piVar13 = (int *)param_3[4];
              iVar4 = 0;
              if (piVar13 == (int *)0x0) {
                atof(*(char **)(local_50 + 0x18));
              }
              else {
                while( true ) {
                  if (*piVar13 <= iVar4) {
                    if (uac_comm_err_switch == 0) goto LAB_00514b84;
                    uVar10 = 0x672;
                    iVar8 = param_3[1];
                    pcVar6 = "[UAC_COMM_ERR]%s()/line %d : [%s]transfer string to double failed.\n";
                    pcVar7 = "_uac_com_uci_float_prase";
                    goto LAB_005150cc;
                  }
                  puVar15 = (undefined4 *)(piVar13[1] + iVar4 * 0x10);
                  if (((char *)*puVar15 != (char *)0x0) &&
                     (iVar3 = strcmp((char *)*puVar15,*(char **)(iVar8 + 0x18)), iVar3 == 0)) break;
                  iVar4 = iVar4 + 1;
                }
                iVar14 = puVar15[3];
                iVar3 = puVar15[2];
              }
              if ((*(short *)((int)param_3 + 0x1a) == 4) || (*(short *)((int)param_3 + 0x1a) != 8))
              {
                puVar15 = (undefined4 *)param_3[7];
                uVar10 = __truncdfsf2();
                *puVar15 = uVar10;
                param_3[8] = 1;
              }
              else {
                piVar13 = (int *)param_3[7];
                piVar13[1] = iVar14;
                *piVar13 = iVar3;
                param_3[8] = 1;
              }
            }
            else {
              iVar3 = 0;
              iVar8 = 0;
              for (piVar13 = *(int **)(local_50 + 0x18); piVar13 != (int *)(local_50 + 0x18);
                  piVar13 = (int *)*piVar13) {
                piVar12 = &uac_comm_err_switch;
                if ((int)(uint)*(ushort *)(param_3 + 6) <= iVar8) {
                  if (uac_comm_err_switch == 0) goto LAB_00514b84;
                  uVar10 = 0x67f;
                  iVar8 = param_3[1];
                  pcVar6 = "[UAC_COMM_ERR]%s()/line %d : [%s]element out of range\n";
                  pcVar7 = "_uac_com_uci_float_prase";
                  goto LAB_005150cc;
                }
                piVar11 = (int *)param_3[4];
                iVar4 = 0;
                if (piVar11 == (int *)0x0) {
                  atof((char *)piVar13[3]);
                  iVar4 = iVar14;
                }
                else {
                  while( true ) {
                    if (*piVar11 <= iVar4) {
                      if (uac_comm_err_switch == 0) goto LAB_00514b84;
                      uVar10 = 0x685;
                      iVar8 = param_3[1];
                      pcVar6 = 
                      "[UAC_COMM_ERR]%s()/line %d : [%s]transfer string to double failed.\n";
                      pcVar7 = "_uac_com_uci_float_prase";
                      goto LAB_005150cc;
                    }
                    puVar15 = (undefined4 *)(piVar11[1] + iVar4 * 0x10);
                    if (((char *)*puVar15 != (char *)0x0) &&
                       (iVar14 = strcmp((char *)*puVar15,(char *)piVar13[3]), iVar14 == 0)) break;
                    iVar4 = iVar4 + 1;
                  }
                  piVar12 = (int *)puVar15[2];
                  iVar4 = puVar15[3];
                }
                if ((*(short *)((int)param_3 + 0x1a) == 4) || (*(short *)((int)param_3 + 0x1a) != 8)
                   ) {
                  iVar4 = param_3[7];
                  uVar17 = __truncdfsf2();
                  iVar14 = (int)uVar17;
                  *(int *)(iVar4 + iVar3) = (int)((ulonglong)uVar17 >> 0x20);
                }
                else {
                  iVar14 = param_3[7];
                  puVar15 = (undefined4 *)(iVar14 + iVar8 * 8);
                  puVar15[1] = iVar4;
                  *puVar15 = piVar12;
                }
                iVar8 = iVar8 + 1;
                iVar3 = iVar3 + 4;
              }
              param_3[8] = iVar8;
            }
          }
          else {
            if (2 < uVar2) {
              if (uVar2 != 4) {
                if (uVar2 == 5) goto LAB_00514cac;
                iVar3 = param_3[5];
                goto LAB_00514b4c;
              }
              iVar3 = param_3[5];
LAB_00514ce0:
              param_3[8] = 0;
              if ((iVar3 == 0) && (param_3[4] == 0)) {
                sprintf(__s,"%s.%s.%s",param_1,param_2,iVar8);
                iVar8 = uci_lookup_ptr(local_38,auStack_60,__s,1);
                if (iVar8 == 0) {
                  if (local_50 != 0) {
                    if (*(int *)(local_50 + 0x14) == 0) {
                      iVar8 = param_3[2];
                      iVar3 = 4;
LAB_00514d90:
                      if (iVar3 == iVar8) {
                        iVar8 = param_3[3];
                        goto LAB_005153f4;
                      }
                      iVar8 = param_3[2];
                    }
                    else {
                      if (*(int *)(local_50 + 0x14) == 1) {
                        iVar3 = param_3[2];
                        iVar8 = 1;
                        goto LAB_00514d90;
                      }
                      iVar8 = param_3[2];
                    }
                    if (iVar8 == 1) {
                      sVar5 = *(ushort *)((int)param_3 + 0x1a) - 1;
                      if (*(ushort *)((int)param_3 + 0x1a) < 2) {
                        sVar5 = 0;
                      }
                      strncpy((char *)param_3[7],*(char **)(local_50 + 0x18),sVar5);
                      *(undefined1 *)(param_3[7] + sVar5) = 0;
                      param_3[8] = 1;
                    }
                    else {
                      iVar8 = 0;
                      for (puVar15 = *(undefined4 **)(local_50 + 0x18);
                          puVar15 != (undefined4 *)(local_50 + 0x18);
                          puVar15 = (undefined4 *)*puVar15) {
                        if ((int)(uint)*(ushort *)(param_3 + 6) <= iVar8) {
                          if (uac_comm_err_switch == 0) goto LAB_00514b84;
                          uVar10 = 0x61a;
                          iVar8 = param_3[1];
                          pcVar6 = "[UAC_COMM_ERR]%s()/line %d : [%s]element out of range\n";
                          pcVar7 = "_uac_com_uci_string_prase";
                          goto LAB_005150cc;
                        }
                        sVar5 = *(ushort *)((int)param_3 + 0x1a) - 1;
                        if (*(ushort *)((int)param_3 + 0x1a) < 2) {
                          sVar5 = 0;
                        }
                        if (param_3[2] == 1) {
                          strncpy((char *)param_3[7],(char *)puVar15[3],sVar5);
                          iVar3 = param_3[7];
                        }
                        else {
                          piVar13 = (int *)(param_3[7] + iVar8 * 4);
                          strncpy((char *)*piVar13,(char *)puVar15[3],sVar5);
                          iVar3 = *piVar13;
                        }
                        iVar8 = iVar8 + 1;
                        *(undefined1 *)(iVar3 + sVar5) = 0;
                      }
                      param_3[8] = iVar8;
                    }
                    goto LAB_00514f10;
                  }
                  iVar8 = param_3[3];
                }
                else {
                  iVar8 = param_3[3];
                }
LAB_005153f4:
                if (iVar8 == 0) goto LAB_00514f10;
                if (uac_comm_err_switch != 0) {
                  uVar10 = 0x5f4;
                  iVar8 = param_3[1];
                  pcVar6 = 
                  "[UAC_COMM_ERR]%s()/line %d : not_null option[%s] not found or type mismatch\n";
                  pcVar7 = "_uac_com_uci_string_prase";
LAB_005150cc:
                  printf(pcVar6,pcVar7,uVar10,iVar8);
                }
              }
              else if (uac_comm_err_switch != 0) {
                uVar10 = 0x5e7;
                pcVar6 = "_uac_com_uci_string_prase";
                goto LAB_00514d0c;
              }
              goto LAB_00514b84;
            }
            iVar3 = param_3[5];
            if (uVar2 == 1) goto LAB_00514ce0;
LAB_00514b4c:
            param_3[8] = 0;
            if ((((iVar3 != 10) && (iVar3 != 0x10)) && (iVar3 != 8)) && (iVar3 != 2)) {
              if (uac_comm_err_switch != 0) {
                uVar10 = 0x577;
                pcVar6 = "[UAC_COMM_ERR]%s()/line %d : [%s]base not valid\n";
                pcVar7 = "_uac_com_uci_int_prase";
                goto LAB_005150cc;
              }
              goto LAB_00514b84;
            }
            sprintf(__s,"%s.%s.%s",param_1,param_2,iVar8);
            iVar3 = uci_lookup_ptr(local_38,auStack_60,__s,1);
            iVar8 = local_50;
            if (iVar3 == 0) {
              if (local_50 == 0) {
                iVar8 = param_3[3];
                goto LAB_00514e5c;
              }
              if (*(int *)(local_50 + 0x14) == 0) {
                if (param_3[2] != 3) {
                  iVar3 = param_3[2];
                  goto LAB_00514c48;
                }
                iVar8 = param_3[3];
                goto LAB_00514e5c;
              }
              iVar3 = param_3[2];
              if (*(int *)(local_50 + 0x14) == 1) {
                if (iVar3 == 0) goto LAB_00514e58;
                piVar13 = *(int **)(local_50 + 0x18);
LAB_00515108:
                iVar3 = 0;
                iVar8 = 0;
                for (; piVar13 != (int *)(local_50 + 0x18); piVar13 = (int *)*piVar13) {
                  if ((int)(uint)*(ushort *)(param_3 + 6) <= iVar8) {
                    if (uac_comm_err_switch == 0) goto LAB_00514b84;
                    uVar10 = 0x5c8;
                    iVar8 = param_3[1];
                    pcVar6 = "[UAC_COMM_ERR]%s()/line %d : [%s]element out of range\n";
                    pcVar7 = "_uac_com_uci_int_prase";
                    goto LAB_005150cc;
                  }
                  piVar12 = (int *)param_3[4];
                  iVar14 = 0;
                  if (piVar12 == (int *)0x0) {
                    lVar16 = strtoll((char *)piVar13[3],(char **)0x0,param_3[5]);
                  }
                  else {
                    while( true ) {
                      if (*piVar12 <= iVar14) {
                        if (uac_comm_err_switch == 0) goto LAB_00514b84;
                        uVar10 = 0x5cf;
                        iVar8 = param_3[1];
                        pcVar6 = 
                        "[UAC_COMM_ERR]%s()/line %d : [%s]transfer string to llint failed.\n";
                        pcVar7 = "_uac_com_uci_int_prase";
                        goto LAB_005150cc;
                      }
                      puVar15 = (undefined4 *)(piVar12[1] + iVar14 * 0x10);
                      pcVar6 = (char *)*puVar15;
                      if ((pcVar6 != (char *)0x0) &&
                         (iVar4 = strcmp(pcVar6,(char *)piVar13[3]), iVar4 == 0)) break;
                      iVar14 = iVar14 + 1;
                    }
                    lVar16 = *(longlong *)(puVar15 + 2);
                  }
                  uVar1 = *(ushort *)((int)param_3 + 0x1a);
                  if (uVar1 == 2) {
                    *(short *)(param_3[7] + iVar8 * 2) = (short)lVar16;
                  }
                  else if (uVar1 < 3) {
                    if (uVar1 != 1) goto LAB_005151a4;
                    *(char *)(param_3[7] + iVar8) = (char)lVar16;
                  }
                  else {
                    if (uVar1 == 4) {
LAB_005151a4:
                      iVar14 = param_3[7];
                    }
                    else {
                      if (uVar1 == 8) {
                        *(longlong *)(param_3[7] + iVar8 * 8) = lVar16;
                        goto LAB_005151c4;
                      }
                      iVar14 = param_3[7];
                    }
                    *(int *)(iVar14 + iVar3) = (int)lVar16;
                  }
LAB_005151c4:
                  iVar8 = iVar8 + 1;
                  iVar3 = iVar3 + 4;
                }
                param_3[8] = iVar8;
              }
              else {
LAB_00514c48:
                if (iVar3 != 0) {
                  piVar13 = *(int **)(local_50 + 0x18);
                  goto LAB_00515108;
                }
                piVar13 = (int *)param_3[4];
                iVar3 = 0;
                if (piVar13 == (int *)0x0) {
                  lVar16 = strtoll(*(char **)(local_50 + 0x18),(char **)0x0,param_3[5]);
                }
                else {
                  while( true ) {
                    if (*piVar13 <= iVar3) {
                      if (uac_comm_err_switch == 0) goto LAB_00514b84;
                      uVar10 = 0x5bb;
                      iVar8 = param_3[1];
                      pcVar6 = "[UAC_COMM_ERR]%s()/line %d : [%s]transfer string to llint failed.\n"
                      ;
                      pcVar7 = "_uac_com_uci_int_prase";
                      goto LAB_005150cc;
                    }
                    puVar15 = (undefined4 *)(piVar13[1] + iVar3 * 0x10);
                    pcVar6 = (char *)*puVar15;
                    if ((pcVar6 != (char *)0x0) &&
                       (iVar14 = strcmp(pcVar6,*(char **)(iVar8 + 0x18)), iVar14 == 0)) break;
                    iVar3 = iVar3 + 1;
                  }
                  lVar16 = *(longlong *)(puVar15 + 2);
                }
                uVar1 = *(ushort *)((int)param_3 + 0x1a);
                if (uVar1 == 2) {
                  *(short *)param_3[7] = (short)lVar16;
                  param_3[8] = 1;
                }
                else {
                  if (uVar1 < 3) {
                    if (uVar1 == 1) {
                      *(char *)param_3[7] = (char)lVar16;
                      param_3[8] = 1;
                      goto LAB_00514f10;
                    }
LAB_005152c0:
                    puVar15 = (undefined4 *)param_3[7];
                  }
                  else {
                    if (uVar1 == 4) goto LAB_005152c0;
                    if (uVar1 == 8) {
                      *(longlong *)param_3[7] = lVar16;
                      param_3[8] = 1;
                      goto LAB_00514f10;
                    }
                    puVar15 = (undefined4 *)param_3[7];
                  }
                  *puVar15 = (int)lVar16;
                  param_3[8] = 1;
                }
              }
            }
            else {
LAB_00514e58:
              iVar8 = param_3[3];
LAB_00514e5c:
              if (iVar8 != 0) {
                if (uac_comm_err_switch != 0) {
                  uVar10 = 0x584;
                  iVar8 = param_3[1];
                  pcVar6 = 
                  "[UAC_COMM_ERR]%s()/line %d : not_null option[%s] not found or type mismatch\n";
                  pcVar7 = "_uac_com_uci_int_prase";
                  goto LAB_005150cc;
                }
                goto LAB_00514b84;
              }
            }
          }
LAB_00514f10:
          param_3 = param_3 + 9;
          uVar10 = 0;
        }
      }
      uci_free_context(local_38);
      if (__s != (char *)0x0) {
        uac_mem_free_my(__s);
      }
    }
  }
  return uVar10;
}


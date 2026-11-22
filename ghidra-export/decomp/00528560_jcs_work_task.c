// func jcs_work_task @ 00528560 size=2800

undefined4 jcs_work_task(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined4 uVar12;
  undefined1 *puVar13;
  int in_t9;
  code *pcVar14;
  undefined8 uVar15;
  int local_260;
  undefined1 auStack_25c [64];
  undefined1 local_21c;
  undefined2 local_218;
  undefined1 auStack_216 [110];
  undefined1 auStack_1a8 [127];
  undefined1 local_129;
  undefined1 auStack_128 [255];
  undefined1 local_29;
  
  (**(code **)(in_t9 + 0x231248))(auStack_128,0,0x100);
  iVar1 = (**(code **)(in_t9 + 0x231158))(1,1,0);
  if (iVar1 < 0) {
    if (**(int **)(in_t9 + 0x230c90) == 0) {
      return 0;
    }
    (**(code **)(in_t9 + 0x231370))
              (*(int *)(in_t9 + 0x230bc8) + 0x4c64,*(int *)(in_t9 + 0x230bc8) + 0x53d8,0xc9);
    return 0;
  }
  (**(code **)(in_t9 + 0x231248))(&local_218,0,0x6e);
  local_218 = 1;
  (**(code **)(in_t9 + 0x2311ec))(auStack_216,param_1);
  local_260 = (**(code **)(in_t9 + 0x2310bc))(auStack_216);
  local_260 = local_260 + 2;
  (**(code **)(in_t9 + 0x2312b8))(param_1);
  iVar2 = (**(code **)(in_t9 + 0x2310c0))(iVar1,&local_218,local_260);
  if (iVar2 < 0) {
    if (**(int **)(in_t9 + 0x230c90) != 0) {
      uVar12 = 0xd5;
      iVar11 = *(int *)(in_t9 + 0x230bc8);
      iVar2 = *(int *)(in_t9 + 0x230bc8) + 0x4c94;
      goto LAB_00529014;
    }
  }
  else {
    iVar2 = uac_mem_malloc_my(0x20001,0xdb);
    if (iVar2 != 0) {
LAB_00528670:
      do {
        iVar11 = *(int *)(in_t9 + 0x230f08);
        do {
          while( true ) {
            if (*(int *)(iVar11 + 0x547c) == 0) {
              (**(code **)(in_t9 + 0x2310cc))(1);
              goto LAB_00528670;
            }
            iVar11 = (**(code **)(in_t9 + 0x231104))(iVar1,iVar2,0x20000,0,&local_218,&local_260);
            if (iVar11 < 1) goto LAB_00528670;
            *(undefined1 *)(iVar2 + iVar11) = 0;
            if (**(int **)(in_t9 + 0x230fac) != 0) {
              (**(code **)(in_t9 + 0x231370))
                        (*(int *)(in_t9 + 0x230bc8) + 0x4ce4,*(int *)(in_t9 + 0x230bc8) + 0x53d8,
                         0xf2);
            }
            if (**(int **)(in_t9 + 0x230fac) != 0) {
              (**(code **)(in_t9 + 0x231370))
                        (*(int *)(in_t9 + 0x230bc8) + 0x4d18,*(int *)(in_t9 + 0x230bc8) + 0x53d8,
                         0xf3,iVar2);
            }
            iVar11 = (**(code **)(in_t9 + 0x231364))(iVar2);
            if (iVar11 == 0) break;
            iVar3 = (**(code **)(in_t9 + 0x2310e4))(iVar11,*(int *)(in_t9 + 0x230c98) + 0x69b8);
            iVar4 = (**(code **)(in_t9 + 0x2310e4))(iVar11,*(int *)(in_t9 + 0x230bc0) + -0x62d4);
            iVar5 = (**(code **)(in_t9 + 0x2310e4))(iVar11,*(int *)(in_t9 + 0x230bc0) + -0x5b38);
            iVar6 = (**(code **)(in_t9 + 0x2310e4))(iVar11,*(int *)(in_t9 + 0x230bbc) + 0x1bac);
            iVar7 = (**(code **)(in_t9 + 0x2310e4))(iVar11,*(int *)(in_t9 + 0x230bc8) + 0x4d64);
            if ((iVar6 == 0) && (iVar7 == 0)) {
              piVar8 = *(int **)(in_t9 + 0x230c90);
LAB_00528964:
              iVar3 = *piVar8;
LAB_00528968:
              iVar4 = 0;
              if (iVar3 != 0) {
                (**(code **)(in_t9 + 0x231370))
                          (*(int *)(in_t9 + 0x230bc8) + 0x4d70,*(int *)(in_t9 + 0x230bc8) + 0x53d8,
                           0x103);
              }
            }
            else {
              piVar8 = *(int **)(in_t9 + 0x230c90);
              if (iVar4 == 0) goto LAB_00528964;
              if (iVar3 == 0) {
                iVar3 = *piVar8;
                goto LAB_00528968;
              }
              if (iVar5 != 0) {
                iVar9 = (**(code **)(in_t9 + 0x231308))(iVar5);
                if (iVar9 == 6) {
                  iVar9 = (**(code **)(in_t9 + 0x2312b0))(iVar5);
                }
                else {
                  if (**(int **)(in_t9 + 0x230c90) != 0) {
                    (**(code **)(in_t9 + 0x231370))
                              (*(int *)(in_t9 + 0x230bb8) + 0x69bc,
                               *(int *)(in_t9 + 0x230bc8) + 0x53d8,0x109);
                  }
                  iVar9 = *(int *)(in_t9 + 0x230c60) + -0x7508;
                }
                (**(code **)(in_t9 + 0x23112c))(auStack_1a8,iVar9,0x7f);
                local_129 = 0;
              }
              iVar9 = (**(code **)(in_t9 + 0x231308))(iVar3);
              if (iVar9 == 6) {
                iVar3 = (**(code **)(in_t9 + 0x2312b0))(iVar3);
              }
              else {
                if (**(int **)(in_t9 + 0x230c90) != 0) {
                  (**(code **)(in_t9 + 0x231370))
                            (*(int *)(in_t9 + 0x230bb8) + 0x69bc,*(int *)(in_t9 + 0x230bc8) + 0x53d8
                             ,0x10b);
                }
                iVar3 = *(int *)(in_t9 + 0x230c60) + -0x7508;
              }
              (**(code **)(in_t9 + 0x23112c))(auStack_25c,iVar3,0x40);
              local_21c = 0;
              iVar3 = (**(code **)(in_t9 + 0x231308))(iVar4);
              if (iVar3 == 3) {
                puVar10 = (undefined1 *)(**(code **)(in_t9 + 0x231234))(iVar4);
LAB_00528ac0:
                piVar8 = *(int **)(in_t9 + 0x230c90);
                puVar13 = puVar10;
                if ((undefined1 *)0x3 < puVar10) goto LAB_00528870;
                if (iVar7 != 0) {
                  iVar3 = (**(code **)(in_t9 + 0x231308))(iVar7);
                  if (iVar3 == 6) {
                    iVar3 = (**(code **)(in_t9 + 0x2312b0))(iVar7);
                  }
                  else {
                    if (**(int **)(in_t9 + 0x230c90) != 0) {
                      (**(code **)(in_t9 + 0x231370))
                                (*(int *)(in_t9 + 0x230bb8) + 0x69bc,
                                 *(int *)(in_t9 + 0x230bc8) + 0x53d8,0x115);
                    }
                    iVar3 = *(int *)(in_t9 + 0x230c60) + -0x7508;
                  }
                  puVar13 = auStack_128;
                  (**(code **)(in_t9 + 0x23112c))(auStack_128,iVar3,0xff);
                  local_29 = 0;
                  iVar3 = (**(code **)(in_t9 + 0x231194))
                                    (puVar13,*(int *)(in_t9 + 0x230bc0) + -0x1948);
                  if (iVar3 != 0) {
                    (**(code **)(in_t9 + 0x231134))(iVar3,0,2);
                    iVar4 = (**(code **)(in_t9 + 0x231070))(iVar3);
                    if (iVar4 == 0) {
                      iVar7 = 0;
                      if (**(int **)(in_t9 + 0x230c90) != 0) {
                        uVar12 = 0x122;
                        iVar4 = *(int *)(in_t9 + 0x230bc8) + 0x4e08;
                        iVar5 = *(int *)(in_t9 + 0x230bc8) + 0x53d8;
LAB_00528cc4:
                        (**(code **)(in_t9 + 0x231370))(iVar4,iVar5,uVar12);
                      }
                      pcVar14 = *(code **)(in_t9 + 0x231124);
LAB_00528b84:
                      iVar4 = 0;
                      (*pcVar14)(iVar3);
                    }
                    else {
                      (**(code **)(in_t9 + 0x231134))(iVar3,0,0);
                      iVar7 = uac_mem_malloc_my(iVar4,0x127);
                      if (iVar7 == 0) {
                        pcVar14 = *(code **)(in_t9 + 0x231124);
                        if (**(int **)(in_t9 + 0x230c90) != 0) {
                          uVar12 = 0x12a;
                          iVar4 = *(int *)(in_t9 + 0x230bc8) + 0x4e2c;
                          iVar5 = *(int *)(in_t9 + 0x230bc8) + 0x53d8;
                          goto LAB_00528cc4;
                        }
                        goto LAB_00528b84;
                      }
                      (**(code **)(in_t9 + 0x231248))(iVar7,0,iVar4);
                      if (**(int **)(in_t9 + 0x230fac) != 0) {
                        (**(code **)(in_t9 + 0x231370))
                                  (*(int *)(in_t9 + 0x230bc8) + 0x4e50,
                                   *(int *)(in_t9 + 0x230bc8) + 0x53d8,0x12e,iVar4,puVar13);
                      }
                      if (**(int **)(in_t9 + 0x230fac) != 0) {
                        (**(code **)(in_t9 + 0x231370))
                                  (*(int *)(in_t9 + 0x230bc8) + 0x4e90,
                                   *(int *)(in_t9 + 0x230bc8) + 0x53d8,0x12f,iVar4);
                      }
                      iVar6 = (**(code **)(in_t9 + 0x23133c))(iVar7,1,iVar4,iVar3);
                      if (iVar4 != iVar6) {
                        pcVar14 = *(code **)(in_t9 + 0x231124);
                        if (**(int **)(in_t9 + 0x230c90) != 0) {
                          uVar12 = 0x133;
                          iVar4 = *(int *)(in_t9 + 0x230bc8) + 0x4eb4;
                          iVar5 = *(int *)(in_t9 + 0x230bc8) + 0x53d8;
                          goto LAB_00528cc4;
                        }
                        goto LAB_00528b84;
                      }
                      if (**(int **)(in_t9 + 0x230fac) != 0) {
                        (**(code **)(in_t9 + 0x231370))
                                  (*(int *)(in_t9 + 0x230bc8) + 0x4ee0,
                                   *(int *)(in_t9 + 0x230bc8) + 0x53d8,0x136,iVar4);
                      }
                      (**(code **)(in_t9 + 0x231124))(iVar3);
                      (**(code **)(in_t9 + 0x2312d0))(iVar11,*(int *)(in_t9 + 0x230bbc) + 0x1bac);
                      iVar6 = (**(code **)(in_t9 + 0x231364))(iVar7);
                      if (iVar6 != 0) {
                        (**(code **)(in_t9 + 0x2311d8))
                                  (iVar11,*(int *)(in_t9 + 0x230bbc) + 0x1bac,iVar6);
                        goto LAB_00528d54;
                      }
                      iVar4 = 0;
                      if (**(int **)(in_t9 + 0x230c90) != 0) {
                        (**(code **)(in_t9 + 0x231370))
                                  (*(int *)(in_t9 + 0x230bc8) + 0x4f10,
                                   *(int *)(in_t9 + 0x230bc8) + 0x53d8,0x142,iVar7);
                      }
                    }
                    goto LAB_00528b94;
                  }
                  iVar4 = 0;
                  if (**(int **)(in_t9 + 0x230c90) == 0) goto LAB_0052887c;
                  uVar12 = 0x119;
                  iVar5 = *(int *)(in_t9 + 0x230bc8);
                  iVar3 = *(int *)(in_t9 + 0x230bc8) + 0x4ddc;
                  goto LAB_00528a9c;
                }
                iVar7 = 0;
LAB_00528d54:
                iVar4 = (**(code **)(in_t9 + 0x23129c))();
                iVar3 = uac_hash_get(*(undefined4 *)(*(int *)(in_t9 + 0x230f08) + 0x5434),
                                     auStack_25c);
                if (iVar3 == 0) {
                  piVar8 = *(int **)(in_t9 + 0x230c90);
LAB_00528f00:
                  pcVar14 = *(code **)(in_t9 + 0x23123c);
                  if (*piVar8 != 0) {
                    (**(code **)(in_t9 + 0x231370))
                              (*(int *)(in_t9 + 0x230bc8) + 0x4f44,
                               *(int *)(in_t9 + 0x230bc8) + 0x53d8,0x14d,auStack_25c,puVar10);
                    goto LAB_00528dac;
                  }
                }
                else {
                  pcVar14 = *(code **)(iVar3 + (int)(puVar10 + 0x10) * 4 + 4);
                  piVar8 = *(int **)(in_t9 + 0x230c90);
                  if (pcVar14 == (code *)0x0) goto LAB_00528f00;
                  (*pcVar14)(iVar6,iVar4);
LAB_00528dac:
                  pcVar14 = *(code **)(in_t9 + 0x23123c);
                }
                iVar3 = (*pcVar14)(iVar4,0);
                if ((iVar5 != 0) && (iVar3 != 0)) {
                  (**(code **)(in_t9 + 0x231248))(&local_218,0,0x6e);
                  local_218 = 1;
                  (**(code **)(in_t9 + 0x2311ec))(auStack_216,auStack_1a8);
                  local_260 = (**(code **)(in_t9 + 0x2310bc))(auStack_216);
                  local_260 = local_260 + 2;
                  do {
                    pcVar14 = *(code **)(in_t9 + 0x2310bc);
                    while( true ) {
                      uVar12 = (*pcVar14)(iVar3);
                      iVar5 = (**(code **)(in_t9 + 0x2311cc))
                                        (iVar1,iVar3,uVar12,0,&local_218,local_260);
                      if (0 < iVar5) goto LAB_00528b94;
                      piVar8 = (int *)(**(code **)(in_t9 + 0x231080))();
                      if (*piVar8 == 0xb) break;
                      pcVar14 = *(code **)(in_t9 + 0x2310bc);
                      if (*piVar8 != 4) goto LAB_00528b94;
                    }
                  } while( true );
                }
LAB_00528b94:
                if (iVar7 != 0) {
                  uac_mem_free_my(iVar7);
                }
              }
              else {
                iVar3 = (**(code **)(in_t9 + 0x231308))();
                if (iVar3 == 2) {
                  uVar15 = (**(code **)(in_t9 + 0x2312c0))(iVar4);
                  puVar10 = (undefined1 *)
                            (**(code **)(in_t9 + 0x231148))
                                      ((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                  goto LAB_00528ac0;
                }
                if (**(int **)(in_t9 + 0x230c90) != 0) {
                  (**(code **)(in_t9 + 0x231370))
                            (*(int *)(in_t9 + 0x230bb8) + 0x6a80,*(int *)(in_t9 + 0x230bc8) + 0x53d8
                             ,0x10c);
                }
                piVar8 = *(int **)(in_t9 + 0x230c90);
                puVar13 = (undefined1 *)0xffffffff;
LAB_00528870:
                iVar4 = 0;
                if (*piVar8 != 0) {
                  uVar12 = 0x10f;
                  iVar5 = *(int *)(in_t9 + 0x230bc8);
                  iVar3 = *(int *)(in_t9 + 0x230bc8) + 0x4db0;
LAB_00528a9c:
                  iVar4 = 0;
                  (**(code **)(in_t9 + 0x231370))(iVar3,iVar5 + 0x53d8,uVar12,puVar13);
                }
              }
            }
LAB_0052887c:
            (**(code **)(in_t9 + 0x231088))(iVar11);
            if (iVar4 != 0) {
              (**(code **)(in_t9 + 0x231088))(iVar4);
            }
            iVar11 = *(int *)(in_t9 + 0x230f08);
            if (**(int **)(in_t9 + 0x230fac) != 0) {
              (**(code **)(in_t9 + 0x231370))
                        (*(int *)(in_t9 + 0x230bc8) + 0x4f88,*(int *)(in_t9 + 0x230bc8) + 0x53d8,
                         0x180);
              goto LAB_00528670;
            }
          }
          iVar11 = *(int *)(in_t9 + 0x230f08);
        } while (**(int **)(in_t9 + 0x230c90) == 0);
        (**(code **)(in_t9 + 0x231370))
                  (*(int *)(in_t9 + 0x230bc8) + 0x4d38,*(int *)(in_t9 + 0x230bc8) + 0x53d8,0xf8,
                   iVar2);
      } while( true );
    }
    pcVar14 = *(code **)(in_t9 + 0x23131c);
    if (**(int **)(in_t9 + 0x230c90) == 0) goto LAB_005289a8;
    uVar12 = 0xde;
    iVar11 = *(int *)(in_t9 + 0x230bc8);
    iVar2 = *(int *)(in_t9 + 0x230bc8) + 0x4cbc;
LAB_00529014:
    (**(code **)(in_t9 + 0x231370))(iVar2,iVar11 + 0x53d8,uVar12);
  }
  pcVar14 = *(code **)(in_t9 + 0x23131c);
LAB_005289a8:
  (*pcVar14)(iVar1);
  return 0;
}


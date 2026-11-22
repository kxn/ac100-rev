// func jcs_send_to_process @ 00529778 size=1

undefined4
jcs_send_to_process(int param_1,int param_2,undefined4 param_3,int param_4,int *param_5,int param_6)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  undefined4 uVar10;
  int in_t9;
  code *pcVar11;
  int aiStack_2a8 [2];
  undefined2 uStack_2a0;
  undefined1 auStack_29e [110];
  undefined1 auStack_230 [128];
  undefined1 auStack_1b0 [128];
  undefined1 auStack_130 [256];
  int iStack_30;
  
  uVar10 = 0xffffffff;
  (**(code **)(in_t9 + 0x230030))(auStack_1b0,0,0x80);
  (**(code **)(in_t9 + 0x230030))(auStack_230,0,0x80);
  aiStack_2a8[0] = 0;
  aiStack_2a8[1] = 0;
  (**(code **)(in_t9 + 0x230030))(auStack_130,0,0x100);
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (param_2 == 0) {
    return 0xffffffff;
  }
  if (param_4 == 0) {
    return 0xffffffff;
  }
  (**(code **)(in_t9 + 0x22febc))
            (auStack_1b0,*(int *)(in_t9 + 0x22f9b0) + 0x51a0,*(int *)(in_t9 + 0x22f9b0) + 0x51c0,
             param_1);
  uVar2 = (**(code **)(in_t9 + 0x22fefc))(0x107e);
  (**(code **)(in_t9 + 0x22febc))(auStack_230,*(int *)(in_t9 + 0x22f9b0) + 0x51e4,auStack_1b0,uVar2)
  ;
  iVar3 = (**(code **)(in_t9 + 0x22ff40))(1,1,0);
  if (iVar3 < 0) {
    if (**(int **)(in_t9 + 0x22fa78) == 0) {
      return 0xffffffff;
    }
    (**(code **)(in_t9 + 0x230158))
              (*(int *)(in_t9 + 0x22f9b0) + 0x51f0,*(int *)(in_t9 + 0x22f9b0) + 0x5430,0x2b0);
    return 0xffffffff;
  }
  (**(code **)(in_t9 + 0x230030))(&uStack_2a0,0,0x6e);
  uStack_2a0 = 1;
  (**(code **)(in_t9 + 0x22ffd4))(auStack_29e,auStack_230);
  iVar4 = (**(code **)(in_t9 + 0x22fea4))(auStack_29e);
  (**(code **)(in_t9 + 0x2300a0))(auStack_230);
  iVar4 = (**(code **)(in_t9 + 0x22fea8))(iVar3,&uStack_2a0,iVar4 + 2);
  if (iVar4 < 0) {
    if (**(int **)(in_t9 + 0x22fa78) != 0) {
      (**(code **)(in_t9 + 0x230158))
                (*(int *)(in_t9 + 0x22f9b0) + 0x4c94,*(int *)(in_t9 + 0x22f9b0) + 0x5430,700);
    }
    iVar6 = 0;
    iVar4 = 0;
    iVar5 = 0;
    goto code_r0x00529ac0;
  }
  iVar4 = (**(code **)(in_t9 + 0x230084))();
  uVar10 = (**(code **)(in_t9 + 0x2300cc))(param_2);
  (**(code **)(in_t9 + 0x22ffc0))(iVar4,*(int *)(in_t9 + 0x22fa80) + 0x69b8,uVar10);
  uVar10 = (**(code **)(in_t9 + 0x230000))(param_3);
  (**(code **)(in_t9 + 0x22ffc0))(iVar4,*(int *)(in_t9 + 0x22f9a8) + -0x62d4,uVar10);
  uVar10 = (**(code **)(in_t9 + 0x2300cc))(auStack_230);
  (**(code **)(in_t9 + 0x22ffc0))(iVar4,*(int *)(in_t9 + 0x22f9a8) + -0x5b38,uVar10);
  uVar10 = (**(code **)(in_t9 + 0x230024))(param_4,0);
  iVar5 = (**(code **)(in_t9 + 0x22fea4))(uVar10);
  if (iVar5 < 0x20002) {
    iVar5 = *(int *)(in_t9 + 0x22f9a4) + 0x1bac;
    iVar6 = param_4;
code_r0x00529b90:
    (**(code **)(in_t9 + 0x22ffc0))(iVar4,iVar5,iVar6);
    (**(code **)(in_t9 + 0x22fe54))(param_4);
    iVar6 = (**(code **)(in_t9 + 0x230024))(iVar4,0);
    if (iVar6 != 0) {
      iVar5 = (**(code **)(in_t9 + 0x22fea4))(iVar6);
      if (iVar5 < 0x20001) {
        (**(code **)(in_t9 + 0x230030))(&uStack_2a0,0,0x6e);
        uStack_2a0 = 1;
        (**(code **)(in_t9 + 0x22ffd4))(auStack_29e,auStack_1b0);
        iStack_30 = (**(code **)(in_t9 + 0x22fea4))(auStack_29e);
        iStack_30 = iStack_30 + 2;
        do {
          iVar7 = (**(code **)(in_t9 + 0x22ffb4))(iVar3,iVar6,iVar5,0,&uStack_2a0,iStack_30);
          if (iVar7 == iVar5) {
            if (param_6 != 0) {
              aiStack_2a8[0] = param_6;
              aiStack_2a8[1] = 0;
              (**(code **)(in_t9 + 0x22ffb8))(iVar3,0xffff,0x1006,aiStack_2a8,8);
            }
            iVar5 = uac_mem_calloc_my(1,0x20001,0x30f);
            if (iVar5 == 0) goto code_r0x00529ee4;
            pcVar11 = *(code **)(in_t9 + 0x22feec);
            goto code_r0x00529e48;
          }
          piVar8 = (int *)(**(code **)(in_t9 + 0x22fe68))();
          iVar9 = *piVar8;
        } while ((iVar9 == 0xb) || (iVar9 == 4));
        piVar8 = *(int **)(in_t9 + 0x22fa78);
        if (**(int **)(in_t9 + 0x22fa78) != 0) {
          uVar10 = (**(code **)(in_t9 + 0x2300c8))(iVar9);
          (**(code **)(in_t9 + 0x230158))
                    (*(int *)(in_t9 + 0x22f9b0) + 0x52e0,*(int *)(in_t9 + 0x22f9b0) + 0x5430,0x302,
                     iVar9,uVar10);
          piVar8 = *(int **)(in_t9 + 0x22fa78);
        }
        if (*piVar8 != 0) {
          (**(code **)(in_t9 + 0x230158))
                    (*(int *)(in_t9 + 0x22f9b0) + 0x5318,*(int *)(in_t9 + 0x22f9b0) + 0x5430,0x303,
                     iVar7,iVar5);
        }
      }
      else if (**(int **)(in_t9 + 0x22fa78) != 0) {
        (**(code **)(in_t9 + 0x230158))
                  (*(int *)(in_t9 + 0x22f9b0) + 0x52a4,*(int *)(in_t9 + 0x22f9b0) + 0x5430,0x2f0);
      }
    }
    iVar6 = 0;
  }
  else {
    if (**(int **)(in_t9 + 0x22fd94) != 0) {
      (**(code **)(in_t9 + 0x230158))
                (*(int *)(in_t9 + 0x22f9b0) + 0x5218,*(int *)(in_t9 + 0x22f9b0) + 0x5430,0x2c9,iVar5
                );
    }
    (**(code **)(in_t9 + 0x22ffb0))(auStack_130,*(int *)(in_t9 + 0x22f9b0) + 0x523c);
    (**(code **)(in_t9 + 0x22ffb0))(auStack_130,param_2);
    iVar6 = (**(code **)(in_t9 + 0x22ff7c))(auStack_130,*(int *)(in_t9 + 0x22f9a8) + -0x7ab8);
    if (iVar6 == 0) {
      if (**(int **)(in_t9 + 0x22fa78) != 0) {
        (**(code **)(in_t9 + 0x230158))
                  (*(int *)(in_t9 + 0x22f9b0) + 0x524c,*(int *)(in_t9 + 0x22f9b0) + 0x5430,0x2cf,
                   auStack_130);
      }
    }
    else {
      iVar5 = (**(code **)(in_t9 + 0x22ff88))(uVar10,iVar5,1,iVar6);
      if (iVar5 == 1) {
        (**(code **)(in_t9 + 0x22ff0c))(iVar6);
        iVar6 = (**(code **)(in_t9 + 0x2300cc))(auStack_130);
        iVar5 = *(int *)(in_t9 + 0x22f9b0) + 0x4d64;
        goto code_r0x00529b90;
      }
      if (**(int **)(in_t9 + 0x22fa78) != 0) {
        (**(code **)(in_t9 + 0x230158))
                  (*(int *)(in_t9 + 0x22f9b0) + 0x5274,*(int *)(in_t9 + 0x22f9b0) + 0x5430,0x2d5);
      }
    }
  }
  iVar5 = 0;
  uVar10 = 0xffffffff;
  goto code_r0x00529ac0;
  while( true ) {
    if (param_6 == 0) {
      piVar8 = (int *)(**(code **)(in_t9 + 0x22fe68))();
      bVar1 = *piVar8 == 0xb || *piVar8 == 4;
    }
    else {
      piVar8 = (int *)(**(code **)(in_t9 + 0x22fe68))();
      bVar1 = *piVar8 == 4;
    }
    pcVar11 = *(code **)(in_t9 + 0x22feec);
    if (!bVar1) break;
code_r0x00529e48:
    iVar6 = (*pcVar11)(iVar3,iVar5,0x20000,0,0,0);
    if (0 < iVar6) goto code_r0x00529ea0;
  }
  if (iVar6 == 0) {
code_r0x00529ea0:
    if (param_5 != (int *)0x0) {
      iVar6 = (**(code **)(in_t9 + 0x23014c))(iVar5);
      *param_5 = iVar6;
      if (iVar6 == 0) {
        if (**(int **)(in_t9 + 0x22fa78) != 0) {
          (**(code **)(in_t9 + 0x230158))
                    (*(int *)(in_t9 + 0x22f9b0) + 0x4d38,*(int *)(in_t9 + 0x22f9b0) + 0x5430,0x328,
                     iVar5);
        }
        goto code_r0x00529ee4;
      }
    }
    iVar6 = 0;
    uVar10 = 0;
  }
  else {
    if (**(int **)(in_t9 + 0x22fa78) != 0) {
      (**(code **)(in_t9 + 0x230158))
                (*(int *)(in_t9 + 0x22f9b0) + 0x5340,*(int *)(in_t9 + 0x22f9b0) + 0x5430,0x31e);
    }
code_r0x00529ee4:
    iVar6 = 0;
    uVar10 = 0xffffffff;
  }
code_r0x00529ac0:
  (**(code **)(in_t9 + 0x2300a0))(auStack_230);
  (**(code **)(in_t9 + 0x230104))(iVar3);
  if (iVar6 != 0) {
    (**(code **)(in_t9 + 0x22ff0c))(iVar6);
  }
  if (iVar5 != 0) {
    uac_mem_free_my(iVar5);
  }
  if (iVar4 != 0) {
    (**(code **)(in_t9 + 0x22fe70))(iVar4);
  }
  return uVar10;
}


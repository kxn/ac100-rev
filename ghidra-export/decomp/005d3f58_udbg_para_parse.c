// func udbg_para_parse @ 005d3f58 size=2996

undefined4 udbg_para_parse(char *param_1,int *param_2)

{
  byte bVar1;
  bool bVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  bool bVar11;
  uint uVar12;
  undefined1 auStack_4d8 [96];
  int local_478;
  byte local_474 [96];
  int local_414;
  undefined4 uStack_410;
  byte abStack_40c [996];
  
  memset(auStack_4d8,0,0x60);
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  if (param_2 == (int *)0x0) {
    return 0xffffffff;
  }
  bVar11 = false;
  iVar8 = 0;
  memset(&local_478,0,0x450);
  uVar12 = 0;
  iVar9 = 0;
LAB_005d3fe0:
  sVar3 = strlen(param_1);
  if (uVar12 < sVar3) {
    bVar1 = param_1[uVar12];
    iVar4 = (int)(char)bVar1;
    switch(iVar9) {
    case 0:
      if ((iVar4 != 0x20) && (iVar4 != 9)) {
        if ((iVar4 != 0x5f) && (0x19 < bVar1 - 0x61)) {
          bVar2 = bVar1 - 0x41 < 0x1a;
          goto LAB_005d4458;
        }
        goto LAB_005d4464;
      }
      if (udbg_debug_switch == 0) {
        uVar12 = uVar12 + 1;
      }
      else {
        printf("[UDBG_DBG]%s()/%d STARTING\n","udbg_state_dump",0x4e0);
        uVar12 = uVar12 + 1;
      }
      goto LAB_005d3fe0;
    case 1:
      if (iVar4 == 0x28) {
LAB_005d459c:
        iVar8 = 0;
        local_478 = 1;
        goto LAB_005d440c;
      }
      bVar2 = iVar8 < 0x60;
      if (iVar4 != 0x5f) {
        uVar5 = (uint)bVar1;
        if (uVar5 - 0x61 < 0x1a) {
          bVar2 = iVar8 < 0x60;
        }
        else if (uVar5 - 0x41 < 0x1a) {
          bVar2 = iVar8 < 0x60;
        }
        else {
          bVar2 = iVar8 < 0x60;
          if (9 < uVar5 - 0x30) {
            if ((iVar4 != 0x20) && (iVar4 != 9)) goto LAB_005d4400;
            goto LAB_005d450c;
          }
        }
      }
LAB_005d4458:
      if (!bVar2) {
        return 0xffffffff;
      }
LAB_005d4464:
      local_474[iVar8] = bVar1;
      iVar8 = iVar8 + 1;
      if (udbg_debug_switch != 0) {
        printf("[UDBG_DBG]%s()/%d WAIT_FUNC_NAME\n","udbg_state_dump",0x4e3);
      }
      iVar9 = 1;
      uVar12 = uVar12 + 1;
      goto LAB_005d3fe0;
    case 2:
      if ((iVar4 != 0x20) && (iVar4 != 9)) {
        if (iVar4 == 0x28) goto LAB_005d459c;
LAB_005d4400:
        iVar8 = 0;
        if (iVar4 != 0x3d) {
          return 0xffffffff;
        }
        local_478 = 0;
        goto LAB_005d440c;
      }
LAB_005d450c:
      if (udbg_debug_switch != 0) {
        printf("[UDBG_DBG]%s()/%d FUNC_NAME_END\n","udbg_state_dump",0x4e6);
      }
      iVar9 = 2;
      uVar12 = uVar12 + 1;
      goto LAB_005d3fe0;
    case 3:
      if ((iVar4 != 0x20) && (iVar4 != 9)) {
        if ((local_478 != 1) || (iVar4 != 0x29)) goto LAB_005d4370;
        break;
      }
LAB_005d440c:
      if (udbg_debug_switch != 0) {
        printf("[UDBG_DBG]%s()/%d WAIT_RECEIVE_FIRST_ARG\n","udbg_state_dump",0x4e9);
      }
      iVar9 = 3;
      uVar12 = uVar12 + 1;
      goto LAB_005d3fe0;
    case 4:
      if ((iVar4 == 0x20) || (iVar4 == 9)) goto LAB_005d40a0;
LAB_005d4370:
      if (iVar4 == 0x22) {
        (&uStack_410)[local_414 * 0x19] = 1;
        goto LAB_005d42b0;
      }
      if (iVar4 == 0x30) goto LAB_005d4638;
      if ((iVar4 - 0x31U & 0xff) < 9) goto LAB_005d42fc;
      if (iVar4 != 0x2d) {
        return 0xffffffff;
      }
      bVar11 = true;
      (&uStack_410)[local_414 * 0x19] = 0;
      iVar9 = iVar8 + local_414 * 100;
      iVar8 = iVar8 + 1;
      abStack_40c[iVar9] = bVar1;
LAB_005d43c8:
      if (udbg_debug_switch != 0) {
        printf("[UDBG_DBG]%s()/%d WAIT_RECEIVE_INTEGER_ARG\n","udbg_state_dump",0x4ec);
      }
      iVar9 = 5;
      uVar12 = uVar12 + 1;
      goto LAB_005d3fe0;
    case 5:
      if ((iVar4 == 0x20) || (iVar4 == 9)) goto LAB_005d43c8;
      if (iVar4 != 0x30) {
        if (8 < (iVar4 - 0x31U & 0xff)) {
          return 0xffffffff;
        }
LAB_005d42fc:
        puVar6 = auStack_4d8 + local_414 * 100;
        (&uStack_410)[local_414 * 0x19] = 0;
        goto LAB_005d4310;
      }
LAB_005d4638:
      (&uStack_410)[local_414 * 0x19] = 0;
      abStack_40c[iVar8 + local_414 * 100] = bVar1;
      iVar8 = iVar8 + 1;
      if (udbg_debug_switch != 0) {
        printf("[UDBG_DBG]%s()/%d WAIT_RECEIVE_OCT_OR_HEX_ARG\n","udbg_state_dump",0x4f8);
      }
      iVar9 = 8;
      uVar12 = uVar12 + 1;
      goto LAB_005d3fe0;
    case 6:
      if (iVar4 == 0x22) {
        local_414 = local_414 + 1;
        iVar8 = 0;
        if (10 < local_414) {
          return 0xffffffff;
        }
LAB_005d4584:
        if (udbg_debug_switch != 0) {
          printf("[UDBG_DBG]%s()/%d RECEIVE_STRING_ARG_END\n","udbg_state_dump",0x4f5);
        }
        iVar9 = 7;
        uVar12 = uVar12 + 1;
      }
      else {
        if (0x5f < iVar8) {
          return 0xffffffff;
        }
        iVar9 = iVar8 + local_414 * 100;
        iVar8 = iVar8 + 1;
        abStack_40c[iVar9] = bVar1;
LAB_005d42b0:
        if (udbg_debug_switch != 0) {
          printf("[UDBG_DBG]%s()/%d WAIT_RECEIVE_STRING_ARG\n","udbg_state_dump",0x4f2);
        }
        iVar9 = 6;
        uVar12 = uVar12 + 1;
      }
      goto LAB_005d3fe0;
    case 7:
      if ((iVar4 == 0x20) || (iVar4 == 9)) goto LAB_005d4584;
      if (local_478 != 1) {
        return 0xffffffff;
      }
      if (iVar4 != 0x29) {
        if (iVar4 != 0x2c) {
          return 0xffffffff;
        }
        goto LAB_005d40a0;
      }
      break;
    case 8:
      if ((iVar4 == 0x20) || (iVar4 == 9)) {
LAB_005d4544:
        if (udbg_debug_switch != 0) {
          printf("[UDBG_DBG]%s()/%d unknown state\n","udbg_state_dump",0x507);
        }
        iVar9 = 0xc;
        uVar12 = uVar12 + 1;
      }
      else {
        if ((iVar4 != 0x78) && (iVar4 != 0x58)) {
          if ((iVar4 - 0x30U & 0xff) < 8) goto LAB_005d4210;
          goto LAB_005d45a8;
        }
LAB_005d4608:
        abStack_40c[iVar8 + local_414 * 100] = bVar1;
        iVar8 = iVar8 + 1;
        if (udbg_debug_switch != 0) {
          printf("[UDBG_DBG]%s()/%d WAIT_RECEIVE_HEX_ARG\n","udbg_state_dump",0x501);
        }
        iVar9 = 0xb;
        uVar12 = uVar12 + 1;
      }
      goto LAB_005d3fe0;
    case 9:
      if ((iVar4 == 0x20) || (iVar4 == 9)) goto LAB_005d4544;
      if (9 < (iVar4 - 0x30U & 0xff)) goto LAB_005d45a8;
      bVar2 = iVar8 < 0x15;
      if (bVar11) {
        if (bVar11) {
          bVar2 = iVar8 < 0x16;
          goto LAB_005d41b4;
        }
      }
      else {
LAB_005d41b4:
        if (!bVar2) {
          return 0xffffffff;
        }
      }
      puVar6 = auStack_4d8 + local_414 * 100;
LAB_005d4310:
      puVar6[iVar8 + 0xcc] = bVar1;
      iVar8 = iVar8 + 1;
      if (udbg_debug_switch != 0) {
        printf("[UDBG_DBG]%s()/%d WAIT_RECEIVE_DEC_ARG\n","udbg_state_dump",0x4fb);
      }
      iVar9 = 9;
      uVar12 = uVar12 + 1;
      goto LAB_005d3fe0;
    case 10:
      if ((iVar4 == 0x20) || (iVar4 == 9)) goto LAB_005d4544;
      if ((iVar4 - 0x30U & 0xff) < 8) {
        bVar2 = iVar8 < 0x18;
        if (((!bVar11) || (bVar2 = iVar8 < 0x19, bVar11)) && (!bVar2)) {
          return 0xffffffff;
        }
LAB_005d4210:
        abStack_40c[iVar8 + local_414 * 100] = bVar1;
        iVar8 = iVar8 + 1;
        if (udbg_debug_switch != 0) {
          printf("[UDBG_DBG]%s()/%d WAIT_RECEIVE_OCT_ARG\n","udbg_state_dump",0x4fe);
        }
        iVar9 = 10;
        uVar12 = uVar12 + 1;
        goto LAB_005d3fe0;
      }
LAB_005d45a8:
      if (local_478 != 1) {
        return 0xffffffff;
      }
      if (iVar4 != 0x29) {
        if (iVar4 != 0x2c) {
          return 0xffffffff;
        }
        goto LAB_005d45d0;
      }
LAB_005d4a20:
      local_414 = local_414 + 1;
      bVar11 = false;
      if (10 < local_414) {
LAB_005d400c:
        return 0xffffffff;
      }
      iVar8 = 0;
      break;
    case 0xb:
      if ((iVar4 == 0x20) || (iVar4 == 9)) {
        if (bVar11) {
          if ((bVar11) && (iVar8 < 4)) {
            return 0xffffffff;
          }
          bVar11 = false;
        }
        else if (iVar8 < 3) {
          return 0xffffffff;
        }
        goto LAB_005d4544;
      }
      uVar5 = (uint)bVar1;
      if (((uVar5 - 0x30 < 10) || (uVar5 - 0x61 < 6)) || (uVar5 - 0x41 < 6)) {
        bVar2 = iVar8 < 0x12;
        if (((!bVar11) || (bVar2 = iVar8 < 0x13, bVar11)) && (!bVar2)) {
          return 0xffffffff;
        }
        goto LAB_005d4608;
      }
      if (local_478 != 1) {
        return 0xffffffff;
      }
      if (iVar4 == 0x29) {
        if (bVar11) {
          if ((bVar11) && (iVar8 < 4)) {
            return 0xffffffff;
          }
        }
        else if (iVar8 < 3) {
          return 0xffffffff;
        }
        goto LAB_005d4a20;
      }
      if (iVar4 != 0x2c) {
        return 0xffffffff;
      }
      if (bVar11) {
        if ((bVar11) && (iVar8 < 4)) {
          return 0xffffffff;
        }
      }
      else if (iVar8 < 3) {
        return 0xffffffff;
      }
LAB_005d45d0:
      local_414 = local_414 + 1;
      bVar11 = false;
      if (10 < local_414) {
        return 0xffffffff;
      }
      iVar8 = 0;
LAB_005d40a0:
      if (udbg_debug_switch != 0) {
        printf("[UDBG_DBG]%s()/%d WAIT_RECEIVE_ARG\n","udbg_state_dump",0x4ef);
      }
      iVar9 = 4;
      uVar12 = uVar12 + 1;
      goto LAB_005d3fe0;
    case 0xc:
      if ((iVar4 == 0x20) || (iVar4 == 9)) goto LAB_005d4544;
      if (local_478 != 1) {
        return 0xffffffff;
      }
      if (iVar4 != 0x29) {
        if (iVar4 != 0x2c) {
          return 0xffffffff;
        }
        local_414 = local_414 + 1;
        iVar8 = 0;
        if (10 < local_414) {
          return 0xffffffff;
        }
        goto LAB_005d40a0;
      }
      local_414 = local_414 + 1;
      iVar8 = 0;
      if (10 < local_414) {
        return 0xffffffff;
      }
      break;
    case 0xd:
      if ((iVar4 != 0x20) && (iVar4 != 9)) {
        return 0xffffffff;
      }
      break;
    default:
      goto LAB_005d400c;
    }
    if (udbg_debug_switch != 0) {
      printf("[UDBG_DBG]%s()/%d ENDING\n","udbg_state_dump",0x504);
    }
    iVar9 = 0xd;
    uVar12 = uVar12 + 1;
    goto LAB_005d3fe0;
  }
  if (local_478 == 1) {
    iVar8 = 0xd;
  }
  else {
    if (local_478 != 0) {
      return 0xffffffff;
    }
    if ((iVar9 - 8U < 3) || (iVar9 == 0xc)) goto LAB_005d49b0;
    if (iVar9 == 0xb) {
      if (bVar11) {
        if ((bVar11) && (sVar3 = strlen((char *)abStack_40c), 3 < sVar3)) goto LAB_005d49b0;
      }
      else {
        sVar3 = strlen((char *)abStack_40c);
        if (2 < sVar3) {
LAB_005d49b0:
          local_414 = local_414 + 1;
          goto LAB_005d46b8;
        }
      }
    }
    if (iVar9 - 1U < 2) goto LAB_005d46b8;
    iVar8 = 7;
  }
  if (iVar9 != iVar8) {
    return 0xffffffff;
  }
LAB_005d46b8:
  memcpy(param_2,&local_478,0x450);
  if (udbg_debug_switch == 0) {
    iVar8 = *param_2;
  }
  else {
    printf("[UDBG_DBG]%s()/%d ===============DUMP PARA START===============\n","udbg_para_dump",
           0x511);
    iVar8 = *param_2;
  }
  if (iVar8 == 0) {
    if (udbg_debug_switch == 0) {
      iVar8 = param_2[0x19];
    }
    else {
      printf("[UDBG_DBG]%s()/%d variable name:\t%s\n","udbg_para_dump",0x522,param_2 + 1);
      iVar8 = param_2[0x19];
    }
    if (iVar8 == 1) {
      if (udbg_debug_switch == 0) {
        return 0;
      }
      if (param_2[0x1a] == 0) {
        pcVar7 = "integer";
      }
      else {
        pcVar7 = "string";
      }
      printf("[UDBG_DBG]%s()/%d variable type:%s\tvalue:%s\n","udbg_para_dump",0x525,pcVar7,
             param_2 + 0x1b);
    }
  }
  else {
    if (udbg_debug_switch != 0) {
      printf("[UDBG_DBG]%s()/%d func name:\t%s\n","udbg_para_dump",0x515,param_2 + 1);
    }
    if (udbg_debug_switch == 0) {
      iVar8 = param_2[0x19];
    }
    else {
      printf("[UDBG_DBG]%s()/%d para cnt:\t%d\n","udbg_para_dump",0x516,param_2[0x19]);
      iVar8 = param_2[0x19];
    }
    if (0 < iVar8) {
      if (udbg_debug_switch != 0) {
        printf("[UDBG_DBG]%s()/%d para list:\n","udbg_para_dump",0x519);
      }
      piVar10 = param_2;
      for (iVar8 = 0; iVar8 < param_2[0x19]; iVar8 = iVar8 + 1) {
        if (udbg_debug_switch != 0) {
          pcVar7 = "string";
          if (piVar10[0x1a] == 0) {
            pcVar7 = "integer";
          }
          printf("[UDBG_DBG]%s()/%d para type:%s\tvalue:%s\n","udbg_para_dump",0x51c,pcVar7,
                 param_2 + iVar8 * 0x19 + 0x1b);
        }
        piVar10 = piVar10 + 0x19;
      }
    }
  }
  if (udbg_debug_switch != 0) {
    printf("[UDBG_DBG]%s()/%d ===============DUMP PARA END===============\n","udbg_para_dump",0x529)
    ;
  }
  return 0;
}


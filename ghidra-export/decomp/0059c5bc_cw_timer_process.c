// func cw_timer_process @ 0059c5bc size=392

void cw_timer_process(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  undefined8 uVar6;
  
  if (param_1 == 0) {
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d The cw_timer is NULL\n","cw_timer_process",0x112);
      return;
    }
  }
  else {
    iVar4 = 0;
    uVar6 = FUN_00524078();
    uVar1 = (uint)((ulonglong)uVar6 >> 0x20);
    iVar3 = 0;
LAB_0059c60c:
    if (iVar3 < *(int *)(param_1 + 4)) {
      iVar2 = *(int *)(param_1 + 0x10);
      while (iVar2 = FUN_004081b0(iVar2 + iVar3 * 0xc), iVar2 != 0) {
        if (uVar1 < *(uint *)(iVar2 + 0x10)) {
          iVar3 = iVar3 + 1;
          goto LAB_0059c60c;
        }
        if (*(uint *)(iVar2 + 0x10) == uVar1) {
          if ((uint)uVar6 < *(uint *)(iVar2 + 0x14)) break;
          pcVar5 = *(code **)(iVar2 + 0x1c);
        }
        else {
          pcVar5 = *(code **)(iVar2 + 0x1c);
        }
        *(undefined4 *)(iVar2 + 0x28) = 1;
        if (pcVar5 != (code *)0x0) {
          (*pcVar5)(*(undefined4 *)(iVar2 + 0x24));
        }
        FUN_00408500(iVar2);
        if (*(code **)(iVar2 + 0x20) != (code *)0x0) {
          (**(code **)(iVar2 + 0x20))(*(undefined4 *)(iVar2 + 0x24));
        }
        FUN_00407df0(iVar2);
        iVar4 = iVar4 + 1;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
        if (*(int *)(param_1 + 0xc) <= iVar4) {
          return;
        }
        iVar2 = *(int *)(param_1 + 0x10);
      }
      iVar3 = iVar3 + 1;
      goto LAB_0059c60c;
    }
  }
  return;
}


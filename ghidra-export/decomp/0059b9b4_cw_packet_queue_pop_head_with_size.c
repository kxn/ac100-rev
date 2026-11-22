// func cw_packet_queue_pop_head_with_size @ 0059b9b4 size=400

undefined4 cw_packet_queue_pop_head_with_size(undefined4 *param_1,uint param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 local_20 [12];
  
  local_20[0] = 0;
  if ((param_1 == (undefined4 *)0x0) || (param_3 == 0)) {
    uVar5 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d capwap packet queue is not inited or result list is NULL.\n",
             "cw_packet_queue_pop_head_with_size",0x143);
    }
  }
  else {
    uVar6 = 0;
    FUN_004082d0(*param_1,0xffffffff);
    if (*(int *)(param_1[3] + 8) == 0) {
      uVar4 = *param_1;
    }
    else {
      while (iVar1 = param_1[3], uVar6 != param_2) {
        if (*(int *)(iVar1 + 8) == 0) {
          iVar1 = param_1[3];
          break;
        }
        iVar1 = FUN_00408450(0x10,0x14f);
        if (iVar1 == 0) {
          iVar1 = param_1[3];
          break;
        }
        uVar6 = uVar6 + 1;
        *(undefined4 *)(iVar1 + 0xc) =
             *(undefined4 *)(((int *)param_1[3])[5] + *(int *)param_1[3] * 4);
        FUN_004086b0(param_3,iVar1);
        piVar2 = (int *)param_1[3];
        if (piVar2[4] == 0) {
          trap(7);
        }
        *piVar2 = (*piVar2 + 1) % piVar2[4];
        *(int *)(param_1[3] + 8) = *(int *)(param_1[3] + 8) + -1;
      }
      if (*(int *)(iVar1 + 8) == 0) {
        read(param_1[1],local_20,1);
        iVar1 = param_1[3];
      }
      else {
        iVar1 = param_1[3];
      }
      uVar3 = *(uint *)(iVar1 + 0xc);
      if (~uVar6 < uVar3) {
        uVar3 = uVar3 + 1;
      }
      *(uint *)(iVar1 + 0xc) = uVar6 + uVar3;
      uVar4 = *param_1;
    }
    uVar5 = 0;
    FUN_00407f30(uVar4);
  }
  return uVar5;
}


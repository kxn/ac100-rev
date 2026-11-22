// func cw_priv_chnl_scan_create @ 005adac4 size=612

int cw_priv_chnl_scan_create(undefined1 *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  puVar3 = (undefined1 *)cw_protocol_clone(param_1,8);
  if (puVar3 == (undefined1 *)0x0) {
    iVar4 = 0;
    if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_chnl_scan_create",0xea);
    }
  }
  else {
    *puVar3 = *param_1;
    uVar1 = param_1[1];
    *(undefined4 *)(puVar3 + 4) = 0;
    puVar3[1] = uVar1;
    if (((byte)param_1[1] != 0) && (*(int *)(param_1 + 4) != 0)) {
      iVar4 = cw_protocol_clone(*(int *)(param_1 + 4),(uint)(byte)param_1[1] << 3);
      iVar6 = 0;
      *(int *)(puVar3 + 4) = iVar4;
      if (iVar4 == 0) {
        if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to clone chnl_list\n","cw_priv_chnl_scan_create",0xf8)
          ;
        }
        FUN_00407df0(puVar3);
        return 0;
      }
      for (; iVar6 < (int)(uint)(byte)param_1[1]; iVar6 = iVar6 + 1) {
        *(undefined4 *)(*(int *)(puVar3 + 4) + iVar6 * 8 + 4) = 0;
      }
      iVar4 = 0;
      while (iVar4 < (int)(uint)(byte)param_1[1]) {
        iVar6 = iVar4 * 8;
        *(undefined1 *)(*(int *)(puVar3 + 4) + iVar6) =
             *(undefined1 *)(*(int *)(param_1 + 4) + iVar6);
        *(undefined1 *)(*(int *)(puVar3 + 4) + iVar6 + 1) =
             *(undefined1 *)(*(int *)(param_1 + 4) + iVar6 + 1);
        uVar7 = (uint)*(byte *)(*(int *)(param_1 + 4) + iVar6 + 1);
        if (uVar7 == 0) {
          iVar4 = iVar4 + 1;
        }
        else {
          iVar8 = *(int *)(puVar3 + 4);
          iVar4 = iVar4 + 1;
          uVar5 = cw_protocol_clone(*(undefined4 *)(*(int *)(param_1 + 4) + iVar6 + 4),uVar7 + 1);
          *(undefined4 *)(iVar8 + iVar6 + 4) = uVar5;
        }
      }
    }
    uVar5 = cw_priv_chnl_scan_length(puVar3);
    iVar4 = cw_protocol_msg_ele_create(0x9b,uVar5,puVar3);
    if (iVar4 == 0) {
      iVar4 = 0;
      if (capwap_err_switch != 0) {
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          iVar4 = 0;
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_chnl_scan_create",0x113);
          iVar4 = 0;
        }
      }
      do {
        bVar2 = puVar3[1];
        while( true ) {
          if ((int)(uint)bVar2 <= iVar4) {
            FUN_00407df0(puVar3);
            return 0;
          }
          iVar6 = iVar4 * 8;
          iVar4 = iVar4 + 1;
          if (*(int *)(*(int *)(puVar3 + 4) + iVar6 + 4) == 0) break;
          FUN_00407df0();
          bVar2 = puVar3[1];
        }
      } while( true );
    }
  }
  return iVar4;
}


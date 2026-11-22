// func cw_priv_mesh_public_control_parse @ 005b6b80 size=1164

undefined4 cw_priv_mesh_public_control_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort *__s;
  int iVar3;
  void *pvVar4;
  ushort *puVar5;
  short sVar7;
  uint uVar6;
  char *pcVar8;
  undefined4 uVar9;
  uint uVar10;
  short local_30;
  undefined2 local_2e [3];
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (ushort *)FUN_00408450(0x18,0x93);
  if (__s == (ushort *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_mesh_public_control_parse",0x96);
    return 0xffffffff;
  }
  memset(__s,0,0x18);
  FUN_0051ad88(__s + 6);
  iVar3 = cw_protocol_retrieve16(param_1);
  *__s = (ushort)iVar3;
  if (99 < iVar3 - 1U) {
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(__s), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d ap count(%d) is wrong\n","cw_priv_mesh_public_control_parse",0x9f
             ,(uint)*__s);
    }
    goto LAB_005b6d60;
  }
  if ((int)(uint)*(ushort *)(param_2 + 0xe) < iVar3 * 6 + 4) {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(__s), iVar3 == 0))
    goto LAB_005b6d60;
    uVar6 = (uint)*(ushort *)(param_2 + 0xc);
    uVar10 = (uint)*(ushort *)(param_2 + 0xe);
    pcVar8 = "[CW_ERROR]%32s():%4d length(%d) of private message element(%d) is wrong\n";
    uVar9 = 0xa5;
  }
  else {
    pvVar4 = (void *)FUN_00408450(iVar3 * 6,0xa9);
    *(void **)(__s + 2) = pvVar4;
    if (pvVar4 == (void *)0x0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(__s), iVar3 != 0)) {
        pcVar8 = "[CW_ERROR]%32s():%4d Malloc mac list failed\n";
        uVar9 = 0xac;
LAB_005b6e78:
        printf(pcVar8,"cw_priv_mesh_public_control_parse",uVar9);
      }
      goto LAB_005b6d60;
    }
    memset(pvVar4,0,(uint)*__s * 6);
    uVar2 = *__s;
    for (iVar3 = 0; iVar3 < (int)(uint)uVar2; iVar3 = iVar3 + 1) {
      cw_protocol_retrieve_bytes(param_1,*(int *)(__s + 2) + iVar3 * 6,6);
      uVar2 = *__s;
    }
    iVar3 = cw_protocol_retrieve16(param_1);
    __s[4] = (ushort)iVar3;
    if (iVar3 == (*(ushort *)(param_2 + 0xe) - 4) + (uint)*__s * -6) {
      do {
        uVar2 = *(ushort *)(param_1 + 6);
        while( true ) {
          if ((uint)*(ushort *)(param_2 + 0xe) == (uint)uVar2 - (uint)uVar1) {
            *(ushort **)(param_2 + 0x10) = __s;
            if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
              return 0xffffffff;
            }
            return 0;
          }
          local_2e[0] = 0;
          local_30 = 0;
          iVar3 = cw_msg_ele_format_parse(param_1,local_2e,&local_30);
          if (iVar3 == -1) {
            if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(__s), iVar3 == 0))
            goto LAB_005b6d60;
            pcVar8 = "[CW_ERROR]%32s():%4d failed to parse type and length of message element\n";
            uVar9 = 199;
            goto LAB_005b6e78;
          }
          puVar5 = (ushort *)cw_msg_ele_mngr_get(local_2e[0]);
          if (puVar5 == (ushort *)0x0) break;
          pvVar4 = (void *)FUN_00408450(0x18,0xd7);
          if (pvVar4 == (void *)0x0) {
            if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(__s), iVar3 == 0))
            goto LAB_005b6d60;
            pcVar8 = "[CW_ERROR]%32s():%4d out of memory\n";
            uVar9 = 0xda;
            goto LAB_005b6e78;
          }
          memset(pvVar4,0,0x18);
          FUN_004086b0(__s + 6,pvVar4);
          *(undefined2 *)((int)pvVar4 + 0xc) = local_2e[0];
          *(short *)((int)pvVar4 + 0xe) = local_30;
          *(undefined4 *)((int)pvVar4 + 0x14) = *(undefined4 *)(param_2 + 0x14);
          iVar3 = (**(code **)(puVar5 + 6))(param_1,pvVar4);
          if (iVar3 == -1) {
            if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(__s), iVar3 == 0))
            goto LAB_005b6d60;
            uVar6 = (uint)*puVar5;
            uVar10 = *(uint *)(puVar5 + 2);
            pcVar8 = "[CW_ERROR]%32s():%4d failed to parse %s(%d)\n";
            uVar9 = 0xe6;
            goto LAB_005b6efc;
          }
          uVar2 = *(ushort *)(param_1 + 6);
        }
        if (capwap_err_switch == 0) {
          sVar7 = *(short *)(param_1 + 6);
        }
        else {
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            sVar7 = *(short *)(param_1 + 6);
          }
          else {
            printf("[CW_ERROR]%32s():%4d message element doesn\'t have manager, ignore it\n",
                   "cw_priv_mesh_public_control_parse",0xd0);
            sVar7 = *(short *)(param_1 + 6);
          }
        }
        *(short *)(param_1 + 6) = local_30 + sVar7;
      } while( true );
    }
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(__s), iVar3 == 0))
    goto LAB_005b6d60;
    uVar10 = (uint)__s[4];
    pcVar8 = "[CW_ERROR]%32s():%4d data len(%d) not match length(%d)\n";
    uVar9 = 0xb8;
    uVar6 = (*(ushort *)(param_2 + 0xe) - 4) + (uint)*__s * -6;
  }
LAB_005b6efc:
  printf(pcVar8,"cw_priv_mesh_public_control_parse",uVar9,uVar10,uVar6);
LAB_005b6d60:
  cw_priv_mesh_public_control_val_destroy(__s);
  return 0xffffffff;
}


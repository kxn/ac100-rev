// func _wserv_do_bind_event @ 005ea3e0 size=832

int _wserv_do_bind_event(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined *puVar10;
  undefined4 local_38 [2];
  undefined4 local_30;
  
  local_38[0] = rdmngr_db_generate_ap_id(param_2);
  if (param_1 < 6) {
    if (param_1 == 0) {
      puVar10 = &DAT_007cbf18;
    }
    else {
      if (param_1 != 1) {
        return -1;
      }
      puVar10 = &DAT_007cbf24;
    }
    iVar7 = 0;
    if (*(int *)(puVar10 + 8) != 0) {
      iVar5 = 0;
      FUN_004082d0(DAT_007cbef0,0xffffffff);
      iVar7 = *(int *)(DAT_007cbf08 + param_4 * 4);
      if ((iVar7 != 0) && (iVar7 = FUN_00407fa0(iVar7,local_38), iVar7 != 0)) {
        uVar9 = 0;
        iVar8 = iVar7;
        while (uVar1 = rdmngr_profile_get_max_rd_per_ap(), uVar9 < uVar1) {
          uVar9 = uVar9 + 1;
          uVar1 = 0;
          local_30 = rdmngr_db_generate_rd_id(local_38[0],uVar9);
          iVar2 = rdmngr_db_get_rd_status(local_30);
          if (iVar2 == 0) {
            iVar8 = iVar8 + 4;
          }
          else {
            while (uVar3 = rdmngr_profile_get_max_wlan_per_rd(), iVar2 = DAT_007cbf04, uVar1 < uVar3
                  ) {
              if (*(char *)(*(int *)(iVar8 + 8) + uVar1) == '\0') {
LAB_005ea538:
                uVar1 = uVar1 + 1;
              }
              else {
                iVar4 = rdmngr_db_generate_rd_idx_by_rd_id(local_30);
                uVar3 = (uint)*(short *)(*(int *)(iVar2 + iVar4 * 0xc + 8) + uVar1 * 6 + 2);
                if ((int)uVar3 < 0) goto LAB_005ea538;
                uVar1 = uVar1 + 1;
                if ((uVar3 < l_wserv_profile) &&
                   (iVar2 = DAT_007cbefc + uVar3 * 0x21c, *(int *)(iVar2 + 0xc) != 0)) {
                  iVar5 = iVar5 + (uint)(*(int *)(iVar2 + 299) != 0);
                }
              }
            }
            iVar8 = iVar8 + 4;
          }
        }
        if (param_1 == 0) {
          if (*(char *)(iVar7 + 4) != '\0') {
            bVar6 = *(char *)(iVar7 + 4) - 1;
            *(byte *)(iVar7 + 4) = bVar6;
            iVar5 = iVar5 - (uint)bVar6;
          }
        }
        else if ((param_1 == 1) && (*(char *)(iVar7 + 4) != '\0')) {
          bVar6 = *(char *)(iVar7 + 4) - 1;
          iVar5 = iVar5 + (uint)bVar6;
          *(byte *)(iVar7 + 4) = bVar6;
        }
      }
      FUN_00407f30(DAT_007cbef0);
      if ((g_wserv_debug != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
        printf("<wserv>[debug]%s(): %d  -> _wserv_do_bind_event() do event[%s], ap_id=%d, vlan_id=%d, bind_remain=%d.\r\n"
               ,"_wserv_do_bind_event",0x40d,(&PTR_DAT_006fa204)[param_1],local_38[0],param_4,iVar5)
        ;
      }
      for (iVar7 = FUN_004081b0(puVar10); iVar7 != 0; iVar7 = FUN_00408680(iVar7)) {
        if (*(code **)(iVar7 + 0x30) != (code *)0x0) {
          if ((*(int **)(iVar7 + 0x34) == (int *)0x0) ||
             (iVar8 = **(int **)(iVar7 + 0x34), iVar8 == 0)) {
            iVar8 = 0;
          }
          (**(code **)(iVar7 + 0x30))(local_38[0],param_4,param_3,iVar5,iVar8);
        }
      }
    }
  }
  else {
    iVar7 = -1;
    if ((g_wserv_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("<wserv>[error]%s(): %d  -> invalid event[%d].\r\n","_wserv_do_bind_event",0x3c3,
             param_1);
    }
  }
  return iVar7;
}


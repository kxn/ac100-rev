// func _ap_hash_info_collect @ 005ea274 size=364

void _ap_hash_info_collect(undefined4 *param_1,int *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  uVar7 = 0;
  puVar6 = param_1;
  do {
    uVar1 = rdmngr_profile_get_max_rd_per_ap();
    if (uVar1 <= uVar7) {
      return;
    }
    uVar7 = uVar7 + 1;
    uVar1 = 0;
    uVar2 = rdmngr_db_generate_rd_id(*param_1,uVar7);
    while (uVar3 = rdmngr_profile_get_max_wlan_per_rd(), iVar5 = DAT_007cbf04, uVar1 < uVar3) {
      if (*(char *)(puVar6[2] + uVar1) == '\0') {
LAB_005ea308:
        uVar1 = uVar1 + 1;
      }
      else {
        iVar4 = rdmngr_db_generate_rd_idx_by_rd_id(uVar2);
        uVar3 = (uint)*(short *)(*(int *)(iVar5 + iVar4 * 0xc + 8) + uVar1 * 6 + 2);
        if ((int)uVar3 < 0) goto LAB_005ea308;
        uVar1 = uVar1 + 1;
        if (((uVar3 < l_wserv_profile) &&
            (iVar5 = DAT_007cbefc + uVar3 * 0x21c, *(int *)(iVar5 + 0xc) != 0)) &&
           (*(int *)(iVar5 + 299) != 0)) {
          if (param_2[1] <= *param_2) {
            return;
          }
          *(undefined4 *)(param_2[2] + *param_2 * 4) = *param_1;
          *param_2 = *param_2 + 1;
          return;
        }
      }
    }
    puVar6 = puVar6 + 1;
  } while( true );
}


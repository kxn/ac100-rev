// func _wserv_get_entry @ 005e8f30 size=284

int _wserv_get_entry(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  
  iVar9 = 0;
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id();
  iVar7 = iVar9;
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    iVar5 = rdmngr_profile_get_max_rd_per_ap();
    if ((((uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) && (iVar7 = 0, param_2 != 0)) &&
        (uVar6 = rdmngr_profile_get_max_wlan_per_rd(), iVar7 = iVar9, param_2 <= uVar6)) &&
       (((pcVar8 = (char *)(DAT_007cbf04 + uVar1 * 0xc), *pcVar8 != '\0' &&
         (pcVar8 = (char *)(*(int *)(pcVar8 + 8) + (param_2 - 1) * 6), *pcVar8 != '\0')) &&
        (uVar1 = (uint)*(short *)(pcVar8 + 2), -1 < (int)uVar1)))) {
      if (uVar1 < l_wserv_profile) {
        iVar9 = DAT_007cbefc + uVar1 * 0x21c;
        iVar7 = iVar9 + 0x10;
        if (*(int *)(iVar9 + 0xc) == 0) {
          iVar7 = 0;
        }
      }
      else {
        iVar7 = 0;
      }
    }
  }
  return iVar7;
}


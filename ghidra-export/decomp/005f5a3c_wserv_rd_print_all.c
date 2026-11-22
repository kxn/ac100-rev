// func wserv_rd_print_all @ 005f5a3c size=492

void wserv_rd_print_all(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  if (l_wserv_data != 0) {
    puts("########################################################");
    uVar9 = 0;
    printf("l_wserv_data.rd_used = %d\n",DAT_007cbf00);
    while( true ) {
      iVar1 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_template_max();
      iVar3 = apmngr_db_get_sensor_max();
      iVar4 = rdmngr_profile_get_max_rd_per_ap();
      if ((uint)((iVar1 + iVar2 + iVar3) * iVar4) <= uVar9) break;
      pcVar5 = (char *)(DAT_007cbf04 + uVar9 * 0xc);
      if (*pcVar5 == '\0') {
        uVar9 = uVar9 + 1;
      }
      else {
        if (pcVar5[1] == '\0') {
          pcVar5 = "false";
        }
        else {
          pcVar5 = "true";
        }
        printf("is_firm   = %s\n",pcVar5);
        iVar1 = DAT_007cbf04 + uVar9 * 0xc;
        printf("id        = %d\n",*(undefined4 *)(iVar1 + 4));
        uVar6 = rdmngr_db_generate_rd_idx_by_rd_id(*(undefined4 *)(iVar1 + 4));
        printf("index     = %d\n",uVar6);
        printf("rf_id     = %d\n",*(uint *)(iVar1 + 4) & 0xf);
        puts("wlan      = wlan_id/used/wserv_id/vlan_id");
        uVar8 = 0;
        while( true ) {
          uVar7 = rdmngr_profile_get_max_wlan_per_rd();
          if (uVar7 <= uVar8) break;
          pcVar5 = (char *)(*(int *)(iVar1 + 8) + uVar8 * 6);
          printf("wlan[%d]   = %d/%d/%d/%d\n",uVar8,(uint)(byte)pcVar5[1],(int)*pcVar5,
                 (int)*(short *)(pcVar5 + 2),(int)*(short *)(pcVar5 + 4));
          uVar8 = uVar8 + 1;
        }
        puts("#####################################################################");
        uVar9 = uVar9 + 1;
      }
    }
  }
  FUN_00407f30(DAT_007cbef0);
  return;
}


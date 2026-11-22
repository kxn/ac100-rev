// func _apmngr_db_vlan_get @ 005497ac size=696

undefined4 _apmngr_db_vlan_get(int param_1,int *param_2)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined **ppuVar8;
  undefined *puVar9;
  undefined1 auStack_1a8 [128];
  char acStack_128 [260];
  
  uVar6 = 0;
  memset(auStack_1a8,0,0x80);
  if ((*(int *)(param_1 + 0xc) - 1U < 2) && (*(int *)(param_1 + 0x24) == 0)) {
    param_2[2] = param_2[2] + 1;
    if (*param_2 < 1) {
      if (0 < param_2[1]) {
        iVar2 = json_object_new_object();
        if (iVar2 == 0) {
          if (apmngr_err_switch == '\0') {
            return 1;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return 1;
          }
          uVar5 = 0xac8;
        }
        else {
          memset(acStack_128,0,0x100);
          snprintf(acStack_128,0x100,"%d",(uint)*(ushort *)(param_1 + 0x10));
          uVar6 = json_object_new_string(acStack_128);
          json_object_object_add(iVar2,"ap_id",uVar6);
          mac2str(param_1 + 0x48,auStack_1a8,0x80);
          uVar6 = json_object_new_string(auStack_1a8);
          json_object_object_add(iVar2,"ap_mac",uVar6);
          iVar3 = json_object_new_array();
          if (iVar3 != 0) {
            iVar4 = apdb_radio_count_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218);
            for (iVar7 = 1; iVar7 <= iVar4; iVar7 = iVar7 + 1) {
              uVar6 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),iVar7);
              wserv_db_rd_for_each_wserv(uVar6,0,_apmngr_jcs_ap_vlan_get,iVar3);
            }
            ppuVar8 = &APMNGR_CFG_PHY_WIRE_VLAN;
            json_object_object_add(iVar2,"ssid_vlan",iVar3);
            do {
              puVar9 = *ppuVar8;
              ppuVar8 = ppuVar8 + 1;
              memset(acStack_128,0,0x100);
              puVar1 = (ushort *)(param_1 + 0x128);
              param_1 = param_1 + 2;
              snprintf(acStack_128,0x100,"%d",(uint)*puVar1);
              uVar6 = json_object_new_string(acStack_128);
              json_object_object_add(iVar2,puVar9,uVar6);
            } while (ppuVar8 != (undefined **)&g_apmngr_timer_md5_send_interval_default);
            json_object_array_add(param_2[5],iVar2);
            param_2[1] = param_2[1] + -1;
            return 0;
          }
          json_object_put(iVar2);
          if (apmngr_err_switch == '\0') {
            return 1;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return 1;
          }
          uVar5 = 0xad5;
        }
        uVar6 = 1;
        printf("[APMNGR_ERROR]%s()/%d Create json object failed when get ap vlan info.\n",
               "_apmngr_db_vlan_get",uVar5);
      }
    }
    else {
      *param_2 = *param_2 + -1;
    }
  }
  return uVar6;
}


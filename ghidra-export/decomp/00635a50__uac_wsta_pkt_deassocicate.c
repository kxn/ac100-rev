// func _uac_wsta_pkt_deassocicate @ 00635a50 size=864

undefined4
_uac_wsta_pkt_deassocicate
          (undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *__format;
  undefined4 uVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 auStack_338 [10];
  undefined1 local_32e;
  undefined1 local_32d;
  undefined1 auStack_32c [6];
  byte local_326;
  undefined1 local_324 [2];
  undefined1 auStack_322 [34];
  undefined1 auStack_300 [16];
  undefined2 local_2f0;
  byte local_95;
  
  memset(auStack_338,0,0x38);
  iVar4 = apmngr_db_entry_get_by_mac(param_3,auStack_300);
  if (iVar4 == 0) {
    if ((local_95 & 2) != 0) {
      if ((g_wsta_debug != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("<wsta>[debug]%s(): %d  -> deassoc_mac:%02x:%02x:%02x:%02x:%02x:%02x\r\n",
               "_uac_wsta_pkt_deassocicate",0x2e6,(uint)(byte)param_1[2],(uint)(byte)param_1[3],
               (uint)(byte)param_1[4],(uint)(byte)param_1[5],(uint)(byte)param_1[6],
               (uint)(byte)param_1[7]);
      }
      puVar9 = param_1 + 2;
      iVar4 = wsta_db_get_mac_entry_by_peer(puVar9,auStack_338);
      if ((iVar4 == 0) || (iVar4 = wsta_db_get_mac_entry_by_mld(puVar9,auStack_338), iVar4 == 0)) {
        puVar9 = local_324;
        bVar3 = false;
        iVar6 = 0;
        iVar4 = 0;
        while (iVar6 < (int)(uint)local_326) {
          iVar8 = iVar6 * 0xc;
          uVar2 = *puVar9;
          puVar1 = puVar9 + 1;
          iVar6 = iVar6 + 1;
          puVar9 = puVar9 + 0xc;
          iVar5 = uac_wstation_deassoc(local_2f0,uVar2,*puVar1,auStack_322 + iVar8);
          if (iVar5 != 0) {
            iVar4 = 0x25;
          }
          iVar5 = memcmp(auStack_32c,auStack_322 + iVar8,6);
          if (iVar5 == 0) {
            bVar3 = true;
          }
        }
        if ((bVar3) ||
           (iVar6 = uac_wstation_deassoc(local_2f0,local_32e,local_32d,auStack_32c), iVar6 == 0)) {
          iVar6 = 0;
          if (iVar4 != 0) goto LAB_00635c78;
        }
        else {
          iVar4 = 0x25;
LAB_00635c78:
          iVar6 = -1;
        }
        wsta_db_free_mlo_mac_entry(auStack_338);
        goto LAB_00635bb8;
      }
      if ((g_wsta_debug != 0) && (iVar4 = is_target_debug_ap(local_2f0), iVar4 != 0)) {
        printf("<wsta>[debug]%s(): %d  -> can\'t find mld entry, it\'s normal sta!\n\r\n",
               "_uac_wsta_pkt_deassocicate",0x2eb);
      }
      iVar4 = uac_wstation_deassoc(local_2f0,*param_1,param_1[1],puVar9);
      if (iVar4 != 0) {
        uVar7 = 0x15;
        if (g_wsta_warning == 0) goto LAB_00635ac0;
        iVar4 = is_target_debug_ap(param_4,0x15);
        if (iVar4 != 0) {
          printf("<wsta>[warning]%s(): %d  -> wstation:%02x:%02x:%02x:%02x:%02x:%02x.deassoc fail.\r\n"
                 ,"_uac_wsta_pkt_deassocicate",0x2f0,(uint)(byte)param_1[2],(uint)(byte)param_1[3],
                 (uint)(byte)param_1[4],(uint)(byte)param_1[5],(uint)(byte)param_1[6],
                 (uint)(byte)param_1[7]);
        }
        goto LAB_00635abc;
      }
LAB_00635c00:
      uVar7 = 0;
      goto LAB_00635ac0;
    }
    iVar4 = 0;
    iVar6 = uac_wstation_deassoc(local_2f0,*param_1,param_1[1],param_1 + 2);
LAB_00635bb8:
    if (iVar6 == 0) {
      if (iVar4 == 0) goto LAB_00635c00;
    }
    else if ((g_wsta_warning != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      __format = "<wsta>[warning]%s(): %d  -> uac_wstation_deassoc() fail.\r\n";
      uVar7 = 0x31d;
      goto LAB_00635c2c;
    }
  }
  else if ((g_wsta_warning != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
    __format = "<wsta>[warning]%s(): %d  -> apmngr_db_entry_get_by_mac() fail.\r\n";
    uVar7 = 0x2d3;
LAB_00635c2c:
    printf(__format,"_uac_wsta_pkt_deassocicate",uVar7);
  }
LAB_00635abc:
  uVar7 = 0x15;
LAB_00635ac0:
  _uac_wsta_pkt_set_result_code(param_4,uVar7);
  return 0;
}


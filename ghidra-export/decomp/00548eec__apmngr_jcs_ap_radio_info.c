// func _apmngr_jcs_ap_radio_info @ 00548eec size=868

void _apmngr_jcs_ap_radio_info(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  char *pcVar7;
  uint uVar8;
  undefined1 auStack_4d8 [8];
  char local_4d0;
  char acStack_484 [127];
  undefined1 local_405;
  char acStack_404 [260];
  undefined1 auStack_300 [64];
  undefined4 local_2c0;
  undefined1 auStack_e8 [192];
  
  memset(acStack_484,0,0x80);
  memset(auStack_300,0,0x2d8);
  memset(auStack_4d8,0,0x54);
  iVar1 = json_object_new_array();
  if (iVar1 == 0) {
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Create json object failed when tranverse ap list.\n",
             "_apmngr_jcs_ap_radio_info",0xbe7);
    }
  }
  else {
    iVar2 = json_object_object_get(param_1,"entry_id");
    if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apmngr_jcs_ap_radio_info",0xbec);
      }
      pcVar7 = "";
    }
    else {
      pcVar7 = (char *)json_object_get_string(iVar2);
    }
    strncpy(acStack_484,pcVar7,0x7f);
    local_405 = 0;
    uVar4 = atoi(acStack_484);
    uVar4 = uVar4 & 0xffff;
    iVar2 = apmngr_db_entry_get_by_id(uVar4,auStack_300);
    if (iVar2 == 0) {
      iVar2 = apdb_radio_count_by_id(local_2c0,auStack_e8);
      uVar8 = 1;
      while ((int)uVar8 <= iVar2) {
        uVar5 = rdmngr_db_generate_rd_id(uVar4,uVar8);
        iVar3 = rdmngr_db_rd_entry_get(uVar5,auStack_4d8);
        if (iVar3 == 0) {
          iVar3 = json_object_new_object();
          if (iVar3 == 0) {
            if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[APMNGR_ERROR]%s()/%d Create json object failed when tranverse ap list.\n",
                     "_apmngr_jcs_ap_radio_info",0xc01);
            }
            goto LAB_00549188;
          }
          memset(acStack_404,0,0x100);
          snprintf(acStack_404,0x100,"%d",uVar5 & 0xf);
          uVar6 = json_object_new_string(acStack_404);
          json_object_object_add(iVar3,"freq_unit",uVar6);
          pcVar7 = (char *)apdb_get_radio_freq_name_by_freq((int)local_4d0);
          if (pcVar7 == (char *)0x0) {
            pcVar7 = "---";
          }
          uVar6 = json_object_new_string(pcVar7);
          json_object_object_add(iVar3,"freq_name",uVar6);
          memset(acStack_404,0,0x100);
          uVar6 = wsta_db_get_rd_sta_num(uVar4,uVar8 & 0xff);
          snprintf(acStack_404,0x100,"%d",uVar6);
          uVar8 = uVar8 + 1;
          uVar6 = json_object_new_string(acStack_404);
          json_object_object_add(iVar3,"rf_client_num",uVar6);
          memset(acStack_404,0,0x100);
          uVar6 = rdmngr_db_get_rd_entry_chnl(uVar5);
          snprintf(acStack_404,0x100,"%d",uVar6);
          uVar6 = json_object_new_string(acStack_404);
          json_object_object_add(iVar3,"channel",uVar6);
          json_object_array_add(iVar1,iVar3);
        }
        else {
          uVar8 = uVar8 + 1;
        }
      }
      json_object_object_add(param_2,"rf_entry",iVar1);
    }
    else {
LAB_00549188:
      json_object_put(iVar1);
    }
  }
  return;
}


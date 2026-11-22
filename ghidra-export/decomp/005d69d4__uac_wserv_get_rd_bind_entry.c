// func _uac_wserv_get_rd_bind_entry @ 005d69d4 size=684

undefined4 _uac_wserv_get_rd_bind_entry(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  ushort local_228 [2];
  char acStack_224 [256];
  char acStack_124 [264];
  
  memset(acStack_124,0,0x100);
  local_228[0] = 0;
  iVar1 = json_object_new_object();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
    if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[error]%s(): %d  -> no memory!\r\n","_uac_wserv_get_rd_bind_entry",0x1c4);
    }
  }
  else {
    snprintf(acStack_124,0x100,"%d",param_2);
    uVar2 = json_object_new_string(acStack_124);
    json_object_object_add(iVar1,"radio_id",uVar2);
    uVar2 = json_object_new_string(param_1 + 0x4e);
    json_object_object_add(iVar1,"ap_name",uVar2);
    if (*(int *)(param_1 + 0xc) == 0) {
      pcVar4 = "template";
    }
    else {
      pcVar4 = "ap";
    }
    uVar2 = json_object_new_string(pcVar4);
    json_object_object_add(iVar1,"ap_type",uVar2);
    memset(acStack_224,0,0x100);
    rdmngr_db_generate_ap_id(param_2);
    snprintf(acStack_224,0x100,"%d",param_2 & 0xf);
    uVar2 = json_object_new_string(acStack_224);
    json_object_object_add(iVar1,"freq_unit",uVar2);
    uVar2 = rdmngr_db_get_rd_freq_band(param_2);
    pcVar4 = (char *)apdb_get_radio_freq_name_by_freq(uVar2);
    if (pcVar4 == (char *)0x0) {
      pcVar4 = "---";
    }
    uVar2 = json_object_new_string(pcVar4);
    json_object_object_add(iVar1,"freq_name",uVar2);
    memset(acStack_224,0,0x100);
    uVar2 = rdmngr_db_get_rd_freq_mode(param_2);
    snprintf(acStack_224,0x100,"%d",uVar2);
    uVar2 = json_object_new_string(acStack_224);
    json_object_object_add(iVar1,"freq_mode",uVar2);
    iVar3 = wserv_db_is_wserv_bind_to_rd(param_2,*param_3);
    snprintf(acStack_124,0x100,"%d",iVar3);
    uVar2 = json_object_new_string(acStack_124);
    json_object_object_add(iVar1,"bind_status",uVar2);
    wserv_db_rd_get_bind_vlan_by_wserv_id(param_2,*param_3,local_228);
    uVar5 = 0;
    if (iVar3 != 0) {
      uVar5 = (uint)local_228[0];
    }
    snprintf(acStack_124,0x100,"%d",uVar5);
    uVar2 = json_object_new_string(acStack_124);
    json_object_object_add(iVar1,"vlan_id",uVar2);
    uVar2 = 0;
    json_object_array_add(param_3[8],iVar1);
  }
  return uVar2;
}


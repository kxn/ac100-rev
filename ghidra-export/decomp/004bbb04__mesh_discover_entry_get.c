// func _mesh_discover_entry_get @ 004bbb04 size=1204

undefined4 _mesh_discover_entry_get(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined1 *puVar8;
  undefined4 uVar9;
  char *local_780 [9];
  char acStack_75c [128];
  char acStack_6dc [260];
  undefined1 auStack_5d8 [40];
  ushort local_5b0;
  int local_59c;
  undefined1 auStack_300 [72];
  undefined1 auStack_2b8 [6];
  undefined1 auStack_2b2 [650];
  
  memset(acStack_75c,0,0x80);
  memcpy(local_780 + 3,&PTR_DAT_006a4cf0,0x18);
  local_780[0] = "unknown";
  local_780[1] = "fit";
  local_780[2] = "fat";
  memset(auStack_300,0,0x2d8);
  memset(auStack_5d8,0,0x2d8);
  param_2[2] = param_2[2] + 1;
  if (*param_2 < 1) {
    if (param_2[1] < 1) {
      return 0;
    }
    iVar1 = apmngr_db_entry_get_by_mac(param_1 + 0xc,auStack_5d8);
    if ((iVar1 == 0) && (local_59c == 0)) {
      if ((local_5b0 & 3) != 0) {
        return 0;
      }
      if ((local_5b0 & 4) != 0) {
        return 0;
      }
    }
    iVar1 = json_object_new_object();
    if (iVar1 == 0) {
      if (mesh_err_switch == '\0') {
        return 1;
      }
      uVar2 = 0x259;
    }
    else {
      mac2str(param_1 + 0xc,acStack_75c,0x80);
      uVar2 = json_object_new_string(acStack_75c);
      json_object_object_add(iVar1,"mac",uVar2);
      uVar2 = json_object_new_string(param_1 + 0x12);
      json_object_object_add(iVar1,"model_name",uVar2);
      snprintf(acStack_75c,0x80,"%u.%u",(uint)*(byte *)(param_1 + 0x53),
               (uint)*(byte *)(param_1 + 0x54));
      uVar2 = json_object_new_string(acStack_75c);
      json_object_object_add(iVar1,"hardware_ver",uVar2);
      uVar2 = json_object_new_string(local_780[*(int *)(param_1 + 100) + 3]);
      json_object_object_add(iVar1,"status",uVar2);
      pcVar7 = "unknown";
      if ((*(char *)(param_1 + 0x55) == '\0') && (*(byte *)(param_1 + 0x56) < 3)) {
        pcVar7 = local_780[*(byte *)(param_1 + 0x56)];
      }
      uVar2 = json_object_new_string(pcVar7);
      json_object_object_add(iVar1,"work_mode",uVar2);
      iVar3 = json_object_new_array();
      if (iVar3 != 0) {
        for (iVar4 = FUN_004081b0(param_1 + 0x58); iVar4 != 0; iVar4 = FUN_00408680(iVar4)) {
          iVar5 = json_object_new_object();
          if (iVar5 == 0) {
            if (mesh_err_switch != '\0') {
              printf("[MESH_ERROR]%s()/%d Create json object failed when tranverse ap list.\n",
                     "_mesh_discover_entry_get",0x27e);
            }
            json_object_put(iVar1);
            json_object_put(iVar3);
            return 1;
          }
          uVar2 = mesh_db_uplink_type_str_get(*(undefined1 *)(iVar4 + 0x10));
          uVar2 = json_object_new_string(uVar2);
          json_object_object_add(iVar5,"uplink_type",uVar2);
          memset(acStack_6dc,0,0x100);
          snprintf(acStack_6dc,0x100,"%d",(int)*(char *)(iVar4 + 0x11));
          uVar2 = json_object_new_string(acStack_6dc);
          json_object_object_add(iVar5,"rssi",uVar2);
          memset(acStack_6dc,0,0x100);
          snprintf(acStack_6dc,0x100,"%d",(uint)*(ushort *)(iVar4 + 0xc));
          uVar2 = json_object_new_string(acStack_6dc);
          json_object_object_add(iVar5,"ap_id",uVar2);
          iVar6 = apmngr_db_entry_get_by_id(*(undefined2 *)(iVar4 + 0xc),auStack_300);
          if (iVar6 == 0) {
            mac2str(auStack_2b8,acStack_75c,0x80);
            uVar2 = json_object_new_string(acStack_75c);
            json_object_object_add(iVar5,"ap_mac",uVar2);
            puVar8 = auStack_2b2;
          }
          else {
            uVar2 = json_object_new_string(&DAT_00688af8);
            json_object_object_add(iVar5,"ap_mac",uVar2);
            puVar8 = &DAT_00688af8;
          }
          uVar2 = json_object_new_string(puVar8);
          json_object_object_add(iVar5,"ap_name",uVar2);
          if (*(char *)(iVar4 + 0x18) != '\0') {
            uVar2 = json_object_new_string(&DAT_006a2bcc);
            json_object_object_add(iVar5,"selected",uVar2);
          }
          json_object_array_add(iVar3,iVar5);
        }
        json_object_object_add(iVar1,"cap_info",iVar3);
        json_object_array_add(param_2[5],iVar1);
        param_2[1] = param_2[1] + -1;
        goto LAB_004bbbc4;
      }
      json_object_put(iVar1);
      if (mesh_err_switch == '\0') {
        return 1;
      }
      uVar2 = 0x272;
    }
    uVar9 = 1;
    printf("[MESH_ERROR]%s()/%d Create json object failed when tranverse ap list.\n",
           "_mesh_discover_entry_get",uVar2);
  }
  else {
    *param_2 = *param_2 + -1;
LAB_004bbbc4:
    uVar9 = 0;
  }
  return uVar9;
}


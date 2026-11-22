// func _find_client_object_hash_node @ 0048deb0 size=1136

undefined4
_find_client_object_hash_node
          (undefined4 param_1,byte *param_2,undefined4 *param_3,char *param_4,undefined4 param_5,
          int param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  void *__dest;
  size_t sVar5;
  char *pcVar6;
  undefined4 uVar7;
  char local_4a0 [20];
  char acStack_48c [40];
  undefined1 auStack_464 [128];
  int local_3e4;
  char local_3cc [212];
  undefined1 auStack_2f8 [64];
  undefined4 local_2b8;
  char local_2aa [375];
  undefined1 auStack_133 [83];
  undefined1 auStack_e0 [84];
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_4c;
  
  local_4a0[0] = '\0';
  local_4a0[1] = '\0';
  local_4a0[2] = '\0';
  local_4a0[3] = '\0';
  local_4a0[4] = '\0';
  local_4a0[5] = '\0';
  local_4a0[6] = '\0';
  local_4a0[7] = '\0';
  local_4a0[8] = '\0';
  local_4a0[9] = '\0';
  local_4a0[10] = '\0';
  local_4a0[0xb] = '\0';
  local_4a0[0xc] = '\0';
  local_4a0[0xd] = '\0';
  local_4a0[0xe] = '\0';
  local_4a0[0xf] = '\0';
  local_4a0[0x10] = '\0';
  local_4a0[0x11] = '\0';
  memset(auStack_2f8,0,0x2d8);
  memset(acStack_48c,0,0x28);
  memset(auStack_464,0,0x168);
  iVar1 = apmngr_db_entry_get_by_mac(param_2,auStack_2f8);
  if ((iVar1 == -1) && (param_6 == 0)) {
    return 0xffffffff;
  }
  iVar1 = check_can_direct_report_by_ac(auStack_2f8,param_5);
  if ((iVar1 != 0) && (param_6 == 0)) {
    return 0xffffffff;
  }
  iVar1 = FUN_00407fa0(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_00407ed0(param_1);
    iVar4 = apmngr_db_get_ap_max();
    if (iVar1 < iVar4) {
      __dest = (void *)FUN_00408450(0x10,0x955);
      if (__dest != (void *)0x0) {
        memcpy(__dest,param_2,6);
        uVar2 = json_object_new_object();
        *(undefined4 *)((int)__dest + 8) = uVar2;
        iVar1 = FUN_00408380(param_1,__dest);
        if (iVar1 != 0) {
          if (*(int *)((int)__dest + 8) != 0) {
            json_object_put();
          }
          FUN_00407df0(__dest);
          *param_3 = 0;
          return 0xffffffff;
        }
        iVar1 = FUN_00407fa0(param_1,param_2);
        uVar2 = json_object_new_array();
        snprintf(local_4a0,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*param_2,(uint)param_2[1],
                 (uint)param_2[2],(uint)param_2[3],(uint)param_2[4],(uint)param_2[5]);
        apdb_get_ap_by_id(local_2b8,auStack_e0,auStack_464);
        iVar4 = strcmp("eventList",param_4);
        if (iVar4 == 0) {
          uVar7 = *(undefined4 *)(iVar1 + 8);
          uVar3 = json_object_new_string(local_4a0);
          json_object_object_add(uVar7,"devMac",uVar3);
          if (local_3cc[0] != '\0') {
            uVar7 = *(undefined4 *)(iVar1 + 8);
            uVar3 = json_object_new_string(local_3cc);
            json_object_object_add(uVar7,"devType",uVar3);
          }
          if (local_2aa[0] != '\0') {
            uVar7 = *(undefined4 *)(iVar1 + 8);
            uVar3 = json_object_new_string(local_2aa);
            pcVar6 = "devName";
            goto LAB_0048e204;
          }
        }
        else {
          uVar7 = *(undefined4 *)(iVar1 + 8);
          uVar3 = json_object_new_string(local_4a0);
          json_object_object_add(uVar7,"deviceMac",uVar3);
          uVar7 = *(undefined4 *)(iVar1 + 8);
          uVar3 = json_object_new_string(site_id);
          json_object_object_add(uVar7,"projectId",uVar3);
          pcVar6 = local_3cc;
          uVar7 = *(undefined4 *)(iVar1 + 8);
          if (local_3cc[0] == '\0') {
            if (local_3e4 == 1) {
              pcVar6 = "WIRELESSROUTER";
            }
            else {
              if (local_3e4 != 3) goto LAB_0048e138;
              pcVar6 = "SMBWIRELESSROUTER";
            }
          }
          uVar3 = json_object_new_string(pcVar6);
          pcVar6 = "deviceType";
LAB_0048e204:
          json_object_object_add(uVar7,pcVar6,uVar3);
        }
LAB_0048e138:
        iVar4 = strcmp("clients",param_4);
        if (iVar4 == 0) {
          uVar7 = *(undefined4 *)(iVar1 + 8);
          uVar3 = json_object_new_string(local_2aa);
          json_object_object_add(uVar7,"deviceName",uVar3);
          uVar7 = *(undefined4 *)(iVar1 + 8);
          uVar3 = json_object_new_string(auStack_133);
          json_object_object_add(uVar7,"configId",uVar3);
          uVar7 = *(undefined4 *)(iVar1 + 8);
          uVar3 = json_object_new_boolean(cloud_config_switch);
          json_object_object_add(uVar7,"syncConfig",uVar3);
          FUN_00408190(local_8c,local_88,local_84,local_80,local_7c,acStack_48c,0x28,"0.0.0.0");
          uVar3 = *(undefined4 *)(iVar1 + 8);
          pcVar6 = acStack_48c;
          if (local_4c == 0) {
            pcVar6 = "0.0.0.0";
          }
          uVar7 = json_object_new_string(pcVar6);
          json_object_object_add(uVar3,&DAT_00677c24,uVar7);
          uVar3 = *(undefined4 *)(iVar1 + 8);
        }
        else {
          uVar3 = *(undefined4 *)(iVar1 + 8);
        }
        json_object_object_add(uVar3,param_4,uVar2);
        pcVar6 = (char *)json_object_to_json_string_ext(*(undefined4 *)(iVar1 + 8),0);
        sVar5 = strlen(pcVar6);
        *(size_t *)(iVar1 + 0xc) = sVar5 + 1;
        goto LAB_0048df84;
      }
    }
    else if (cloud_mngt_err_switch != '\0') {
      printf("[CLOUD_MNGT_ERROR]%s()/%d balance_dis_sta_hash is full.\n","create_client_hash_node",
             0x951);
      *param_3 = 0;
      return 0xffffffff;
    }
    *param_3 = 0;
    uVar3 = 0xffffffff;
  }
  else {
    uVar2 = json_object_object_get(*(undefined4 *)(iVar1 + 8),param_4);
LAB_0048df84:
    uVar3 = 0;
    *param_3 = uVar2;
  }
  return uVar3;
}


// func after_handle_client_json @ 00492b40 size=696

undefined4
after_handle_client_json
          (undefined4 *param_1,int param_2,int *param_3,int param_4,int param_5,undefined4 param_6)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  char *pcVar4;
  size_t sVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  
  uVar3 = param_6;
  iVar8 = param_1[0xc];
  pcVar4 = (char *)json_object_to_json_string_ext(param_6,0);
  sVar5 = strlen(pcVar4);
  if ((-1 < (int)(~(sVar5 + param_2) + iVar8)) || (iVar8 = 0, param_1[1] == 0)) {
    iVar8 = 0;
    bVar2 = false;
    goto LAB_00492bb0;
  }
  if (param_2 < 1) {
    iVar6 = param_1[1];
  }
  else {
    iVar8 = FUN_00407fa0(param_1[0xb],param_4 + 0x48);
    FUN_00407f40(param_1[0xb],iVar8);
    *param_3 = iVar8;
    iVar6 = param_1[1];
  }
  if (iVar6 == 0) {
    uVar7 = json_object_new_array();
    param_1[1] = uVar7;
  }
  bVar1 = false;
  FUN_00408570(param_1[0xb],add_client_hash_node,param_1[1]);
  param_1[3] = 0;
  json_object_object_add(*param_1,param_1[5],param_1[1]);
  param_1[1] = 0;
  free_ac_cloud_mngt_hash(param_1 + 0xb,0);
  if (ap_report_switch == 0) {
LAB_00492ce8:
    uVar7 = *param_1;
  }
  else {
    if (client_report_switch != 0) {
      iVar6 = cloud_mngt_obj_send_to_cloud(param_1[6],*param_1);
      bVar1 = iVar6 == 0;
      goto LAB_00492ce8;
    }
    uVar7 = *param_1;
  }
  json_object_object_del(uVar7,param_1[5]);
  param_1[0xc] = 0x3f800;
  param_1[3] = 0;
  pcVar4 = (char *)json_object_to_json_string_ext(*param_1,0);
  sVar5 = strlen(pcVar4);
  param_1[0xc] = ~sVar5 + 0x3f800;
  iVar6 = json_object_new_array();
  param_1[1] = iVar6;
  if (iVar6 == 0) {
    json_object_put(uVar3);
    return 2;
  }
  bVar2 = true;
  uVar7 = apmngr_db_get_ap_max();
  uVar7 = FUN_004080a0(client_handle_hash_obj,client_handle_hash_key,client_handle_hash_cmp,uVar7);
  param_1[0xb] = uVar7;
  param_5 = 0;
  if (!bVar1) {
    return 0xffffffff;
  }
LAB_00492bb0:
  if ((param_1[0xb] != 0) && (iVar8 != 0)) {
    iVar8 = FUN_00408380(param_1[0xb],iVar8);
    if (iVar8 != 0) {
      return 0xffffffff;
    }
    *param_3 = 0;
  }
  if (param_5 == 0) {
    iVar8 = _find_client_object_hash_node(param_1[0xb],param_4 + 0x48,&param_5,"clients",0,0);
    if (iVar8 != 0) {
      return 0xffffffff;
    }
    if (param_5 == 0) {
      return 0xffffffff;
    }
  }
  if (bVar2) {
    iVar8 = FUN_00407fa0(param_1[0xb],param_4 + 0x48);
    param_2 = *(int *)(iVar8 + 0xc);
  }
  json_object_array_add(param_5,uVar3);
  iVar8 = param_1[0xc];
  param_1[3] = param_1[3] + 1;
  pcVar4 = (char *)json_object_to_json_string_ext(uVar3,0);
  sVar5 = strlen(pcVar4);
  param_1[0xc] = ~(param_2 + sVar5) + iVar8;
  return 0;
}


// func _cloud_mngt_mesh_info_add @ 0048c9b4 size=680

void _cloud_mngt_mesh_info_add(int param_1,int param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 auStack_488 [4];
  char local_478 [20];
  undefined1 auStack_464 [128];
  int local_3e4;
  undefined1 auStack_2f8 [64];
  undefined4 local_2b8;
  byte local_2b0;
  byte local_2af;
  byte local_2ae;
  byte local_2ad;
  byte local_2ac;
  byte local_2ab;
  undefined1 auStack_e0 [196];
  
  memset(auStack_2f8,0,0x2d8);
  memset(auStack_464,0,0x168);
  local_478[0] = '\0';
  local_478[1] = '\0';
  local_478[2] = '\0';
  local_478[3] = '\0';
  local_478[4] = '\0';
  local_478[5] = '\0';
  local_478[6] = '\0';
  local_478[7] = '\0';
  local_478[8] = '\0';
  local_478[9] = '\0';
  local_478[10] = '\0';
  local_478[0xb] = '\0';
  local_478[0xc] = '\0';
  local_478[0xd] = '\0';
  local_478[0xe] = '\0';
  local_478[0xf] = '\0';
  local_478[0x10] = '\0';
  local_478[0x11] = '\0';
  memcpy(auStack_488,&PTR_s_AP_0069b39c,0x10);
  if (param_1 == 0) {
    return;
  }
  if ((((param_2 != 1) && (param_2 != 3)) && (param_2 != 2)) &&
     (((param_2 != 4 && (param_2 != 8)) && ((param_2 != 6 && (param_2 != 5)))))) {
    return;
  }
  uVar1 = json_object_new_object();
  if (((param_2 == 1) || (param_2 == 3)) || (param_2 == 2)) {
    pcVar5 = "master";
  }
  else {
    pcVar5 = "slave";
  }
  uVar2 = json_object_new_string(pcVar5);
  json_object_object_add(uVar1,&DAT_00698198,uVar2);
  if (param_4 < 4) {
    pcVar5 = (char *)auStack_488[param_4];
  }
  else {
    pcVar5 = "Unknown";
  }
  uVar2 = json_object_new_string(pcVar5);
  json_object_object_add(uVar1,"type",uVar2);
  if ((((param_2 == 1) || (param_2 == 3)) || (param_2 == 2)) ||
     (iVar3 = apmngr_db_entry_get_by_id(param_3,auStack_2f8), iVar3 != 0)) goto LAB_0048cb48;
  uVar2 = json_object_new_object();
  if (param_3 == 0xffff) {
LAB_0048cb94:
    pcVar5 = "";
  }
  else {
    iVar3 = apmngr_db_entry_get_by_id(param_3,auStack_2f8);
    if (iVar3 != 0) goto LAB_0048cb94;
    snprintf(local_478,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_2b0,(uint)local_2af,
             (uint)local_2ae,(uint)local_2ad,(uint)local_2ac,(uint)local_2ab);
    pcVar5 = local_478;
  }
  uVar4 = json_object_new_string(pcVar5);
  json_object_object_add(uVar2,"mac",uVar4);
  iVar3 = apdb_get_ap_by_id(local_2b8,auStack_e0,auStack_464);
  if (iVar3 == 0) {
    pcVar5 = (char *)auStack_488[local_3e4];
  }
  else {
    pcVar5 = "AP";
  }
  uVar4 = json_object_new_string(pcVar5);
  json_object_object_add(uVar2,"type",uVar4);
  json_object_object_add(uVar1,"masterInfo",uVar2);
LAB_0048cb48:
  json_object_object_add(param_1,"meshInfo",uVar1);
  return;
}


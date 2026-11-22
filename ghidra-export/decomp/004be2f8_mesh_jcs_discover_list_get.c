// func mesh_jcs_discover_list_get @ 004be2f8 size=888

void mesh_jcs_discover_list_get(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__s;
  size_t sVar4;
  FILE *__s_00;
  undefined4 uVar5;
  undefined8 uVar6;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  
  iVar1 = json_object_object_get(param_1,"start");
  if (iVar1 == 0) {
LAB_004be354:
    iVar1 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "mesh_jcs_discover_list_get",0x58a);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_004be354;
      uVar6 = json_object_get_double(iVar1);
      iVar1 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
    }
  }
  iVar2 = json_object_object_get(param_1,"size");
  if (iVar2 != 0) {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      iVar2 = json_object_get_int(iVar2);
      goto LAB_004be3b8;
    }
    iVar3 = json_object_get_type();
    if (iVar3 == 2) {
      uVar6 = json_object_get_double(iVar2);
      iVar2 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
      goto LAB_004be3b8;
    }
  }
  iVar2 = -1;
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "mesh_jcs_discover_list_get",0x58d);
  }
LAB_004be3b8:
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_30 = iVar1;
  local_2c = iVar2;
  local_1c = json_object_new_array();
  local_28 = 0;
  if (mesh_debug_switch != '\0') {
    printf("[MESH_DEBUG]%s()/%d Get discover list from %d to %d.\n","_mesh_discover_list_get",0x2b6,
           iVar1,iVar1 + iVar2);
  }
  if (local_1c == 0) {
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d Failed to create json array.\n","_mesh_discover_list_get",0x2b9);
    }
  }
  else {
    mesh_db_discover_list_foreach_proc(_mesh_discover_entry_get,&local_30);
    __s = (char *)json_object_to_json_string_ext(local_1c,0);
    if (__s == (char *)0x0) {
      if (mesh_err_switch == '\0') {
        __s_00 = (FILE *)0x0;
        iVar1 = 0;
      }
      else {
        __s_00 = (FILE *)0x0;
        printf("[MESH_ERROR]%s()/%d translate json to string failed.\n","_mesh_discover_list_get",
               0x2c2);
        iVar1 = 0;
      }
    }
    else {
      sVar4 = strlen(__s);
      __s_00 = fopen("/tmp/mesh_discover_list","w+");
      if (__s_00 == (FILE *)0x0) {
        iVar1 = 0;
        if (mesh_err_switch != '\0') {
          printf("[MESH_ERROR]%s()/%d open file failed.\n","_mesh_discover_list_get",0x2cb);
          iVar1 = 0;
        }
      }
      else {
        sVar4 = fwrite(__s,sVar4,1,__s_00);
        iVar1 = local_28;
        if ((sVar4 != 1) && (iVar1 = 0, mesh_err_switch != '\0')) {
          printf("[MESH_ERROR]%s()/%d write to file failed.\n","_mesh_discover_list_get",0x2d2);
        }
      }
    }
    if (local_1c != 0) {
      json_object_put();
    }
    if (__s_00 != (FILE *)0x0) {
      fclose(__s_00);
    }
    if (0 < iVar1) {
      uVar5 = json_object_new_string("/tmp/mesh_discover_list");
      json_object_object_add(param_2,"file_name",uVar5);
      uVar5 = json_object_new_int(iVar1);
      json_object_object_add(param_2,"total_num",uVar5);
    }
  }
  return;
}


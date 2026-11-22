// func _apdb_init_json_mem @ 005fa4f0 size=656

undefined4 _apdb_init_json_mem(void)

{
  int iVar1;
  int iVar2;
  char *__n;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  FILE *__s;
  undefined8 uVar7;
  
  if (nego_ap_root != 0) {
    cJSON_Delete();
    nego_ap_root = 0;
  }
  nego_ap_root = cJSON_CreateObject();
  if (nego_ap_root == 0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[APDB_ERROR]%s()/line %d : Failed create nego_ap_root obj.\n";
    uVar5 = 0xeac;
LAB_005fa64c:
    printf(pcVar4,"_apdb_init_json_mem",uVar5);
    return 0xffffffff;
  }
  iVar1 = cJSON_CreateArray();
  if (iVar1 == 0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
    uVar5 = 0xeb4;
    goto LAB_005fa64c;
  }
  uVar7 = __floatsidf(vendor_type);
  iVar2 = cJSON_CreateNumber((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
  if (iVar2 == 0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
    uVar5 = 0xebd;
    goto LAB_005fa64c;
  }
  cJSON_AddItemToObject(nego_ap_root,"vendor",iVar2);
  cJSON_AddItemToObject(nego_ap_root,"ap_item_list",iVar1);
  pcVar4 = (char *)cJSON_Print(nego_ap_root);
  if (pcVar4 == (char *)0x0) {
    return 0xffffffff;
  }
  __n = (char *)strlen(pcVar4);
  if ((0x100000 < (int)__n) || (__n == (char *)0x0)) {
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : file is too large or zero.\n","_apdb_init_json_mem",0xece);
    }
    uVar5 = 0xffffffff;
    __s = (FILE *)0x0;
    goto LAB_005fa5d4;
  }
  __s = fopen("/etc/nouci_config/dbs/apdb_nego.db","w");
  if (__s == (FILE *)0x0) {
    uVar5 = 0xffffffff;
    if (apdb_err_switch == 0) goto LAB_005fa5d4;
    pcVar3 = "[APDB_ERROR]%s()/line %d : Failed to open file[%s]\n";
    uVar6 = 0xed6;
    __n = "/etc/nouci_config/dbs/apdb_nego.db";
  }
  else {
    pcVar3 = (char *)fwrite(pcVar4,1,(size_t)__n,__s);
    if (__n != pcVar3) {
      uVar5 = 0xffffffff;
      if (apdb_err_switch != 0) {
        printf("[APDB_ERROR]%s()/line %d : read apdb data failed.\n","_apdb_init_json_mem",0xede);
      }
      goto LAB_005fa5d4;
    }
    uVar5 = 0;
    if (apdb_debug_switch == 0) goto LAB_005fa5d4;
    pcVar3 = "[APDB_DEBUG]%s()/line %d : read file %d bytes success\n";
    uVar6 = 0xee3;
  }
  printf(pcVar3,"_apdb_init_json_mem",uVar6,__n);
LAB_005fa5d4:
  free(pcVar4);
  if (__s != (FILE *)0x0) {
    fclose(__s);
    return uVar5;
  }
  return uVar5;
}


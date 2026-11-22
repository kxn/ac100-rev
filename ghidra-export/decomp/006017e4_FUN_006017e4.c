// func FUN_006017e4 @ 006017e4 size=1140

undefined4 FUN_006017e4(void)

{
  void *__ptr;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  int iVar6;
  
  __ptr = (void *)FUN_005fc42c();
  if (__ptr == (void *)0x0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    printf("[APDB_ERROR]%s()/line %d : Failed to load json data\n","_apdb_load_json_db",0x1062);
    return 0xffffffff;
  }
  iVar1 = cJSON_Parse(__ptr);
  if (iVar1 == 0) {
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : Fail to parse JSON.\n","_apdb_init_db",0xe49);
    }
    goto LAB_00601a44;
  }
  iVar2 = cJSON_GetObjectItem(iVar1,"ap_list");
  if ((iVar2 == 0) && (iVar2 = iVar1, apdb_debug_switch != 0)) {
    printf("[APDB_DEBUG]%s()/line %d : The whole json data is ap_list\n","_apdb_init_db",0xe51);
  }
  l_max_ap_cnt_new = cJSON_GetArraySize(iVar2);
  if (apdb_debug_switch != 0) {
    printf("[APDB_DEBUG]%s()/line %d : max ap count is : %d \n","_apdb_init_db",0xe54,
           l_max_ap_cnt_new);
  }
  iVar3 = cJSON_GetObjectItem(iVar1,"multi_ap_list");
  iVar2 = l_max_ap_cnt_new;
  if (iVar3 != 0) {
    iVar3 = cJSON_GetArraySize(iVar3);
    l_max_ap_cnt_new = iVar2 + iVar3;
  }
  if (l_max_ap_cnt_new < 0x259) {
    iVar2 = l_apdb_ap_item_cnt_new;
    if (l_max_ap_cnt_new == 0) goto LAB_00601994;
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : max ap count is : %d \n","_apdb_init_db",0xe67);
    }
    l_apdb_ap_item_new = (void *)FUN_00408450(l_max_ap_cnt_new * 0x58,0xe6a);
    if (l_apdb_ap_item_new != (void *)0x0) {
      memset(l_apdb_ap_item_new,0,l_max_ap_cnt_new * 0x58);
      l_apdb_ap_item_cnt_new = 0;
      iVar3 = cJSON_GetObjectItem(iVar1,"ap_list");
      if (iVar3 == 0) {
        iVar6 = 0;
        iVar4 = iVar1;
      }
      else {
        iVar2 = cJSON_GetObjectItem(iVar1,"vendor");
        if ((iVar2 == 0) || (*(int *)(iVar2 + 0xc) != 3)) {
          if (apdb_debug_switch != 0) {
            printf("[APDB_DEBUG]%s()/line %d : apdb vendor error.\n","_apdb_json_parse",0xdb4);
          }
        }
        else if (vendor_type != *(int *)(iVar2 + 0x14)) {
          if (apdb_err_switch != 0) {
            printf("[APDB_ERROR]%s()/line %d : apdb vendor not match[%d/%d].\n","_apdb_json_parse",
                   0xdb8,*(int *)(iVar2 + 0x14),vendor_type);
          }
LAB_00601b28:
          if (apdb_err_switch != 0) {
            __format = "[APDB_ERROR]%s()/line %d : get json information failed.\n";
            uVar5 = 0xe75;
            goto LAB_00601bf0;
          }
          goto LAB_00601b34;
        }
        iVar2 = cJSON_GetObjectItem(iVar1,"multi_ap_list");
        iVar6 = 1;
        iVar4 = iVar3;
        iVar3 = iVar2;
      }
      iVar2 = 0;
      for (; (iVar4 != 0 && (iVar6 != -1)); iVar6 = iVar6 + -1) {
        iVar4 = _apdb_ap_list_parse(iVar4,(void *)((int)l_apdb_ap_item_new + iVar2 * 0x58),0);
        if (iVar4 == -1) {
          if (apdb_err_switch != 0) {
            printf("[APDB_ERROR]%s()/line %d : apdb parse item list error\n","_apdb_json_parse",
                   0xdc5);
          }
          goto LAB_00601b28;
        }
        iVar2 = iVar2 + iVar4;
        iVar4 = iVar3;
      }
LAB_00601994:
      l_apdb_ap_item_cnt_new = iVar2;
      if (apdb_debug_switch != 0) {
        printf("[APDB_DEBUG]%s()/line %d : init db success.[ap item num:%d]\n","_apdb_init_db",0xe7a
               ,l_apdb_ap_item_cnt_new);
      }
      cJSON_Delete(iVar1);
      _apdb_sort_item_array_by_id(l_apdb_ap_item_new,l_apdb_ap_item_cnt_new);
      if (apdb_debug_switch != 0) {
        printf("[APDB_DEBUG]%s()/line %d : load apdb success.\n","_apdb_load_json_db",0x1070);
      }
      free(__ptr);
      return 0;
    }
    if (apdb_err_switch != 0) {
      __format = "[APDB_ERROR]%s()/line %d : Failed to malloc memory for apdb_ap_item.\n";
      uVar5 = 0xe6d;
      goto LAB_00601bf0;
    }
  }
  else if (apdb_warning_switch != 0) {
    __format = "[APDB_WARNING]%s()/line %d : number of APs illegal.\n";
    uVar5 = 0xe5e;
LAB_00601bf0:
    printf(__format,"_apdb_init_db",uVar5);
  }
LAB_00601b34:
  cJSON_Delete(iVar1);
  _apdb_free_new_db();
LAB_00601a44:
  if (apdb_err_switch != 0) {
    printf("[APDB_ERROR]%s()/line %d : Failed to initialize apdb.\n","_apdb_load_json_db",0x1069);
  }
  free(__ptr);
  return 0xffffffff;
}


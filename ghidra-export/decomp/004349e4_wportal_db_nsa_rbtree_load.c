// func wportal_db_nsa_rbtree_load @ 004349e4 size=1412

undefined4 wportal_db_nsa_rbtree_load(int param_1)

{
  int iVar1;
  int iVar2;
  FILE *__stream;
  size_t sVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  size_t __n;
  void *__s;
  undefined8 uVar7;
  char acStack_98 [127];
  undefined1 local_19;
  
  memset(acStack_98,0,0x80);
  if (param_1 == 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[WPORTAL_ERR]%s()/%d input error\n","wportal_db_nsa_rbtree_load",0x1e9f);
    return 0xffffffff;
  }
  iVar1 = json_object_object_get(param_1,"file_name");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "wportal_db_nsa_rbtree_load",0x1ea4);
    }
    pcVar5 = "";
  }
  else {
    pcVar5 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_98,pcVar5,0x7f);
  local_19 = 0;
  iVar1 = json_object_object_get(param_1,"file_size");
  if (iVar1 == 0) {
LAB_00434aac:
    __n = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "wportal_db_nsa_rbtree_load",0x1ea6);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      __n = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_00434aac;
      uVar7 = json_object_get_double(iVar1);
      __n = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d file name = %s, size = %d\n","wportal_db_nsa_rbtree_load",0x1ea7,
           acStack_98,__n);
  }
  __stream = fopen(acStack_98,"rb");
  if (__stream == (FILE *)0x0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[WPORTAL_ERR]%s()/%d Failed to open file[%s]\n","wportal_db_nsa_rbtree_load",0x1eac,
           acStack_98);
    return 0xffffffff;
  }
  fseek(__stream,0,2);
  sVar3 = ftell(__stream);
  if (__n == sVar3) {
    fseek(__stream,0,0);
    __s = (void *)FUN_00408450(__n,0x1eba);
    if (__s == (void *)0x0) {
      if ((wportal_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
      goto LAB_00434b0c;
      pcVar5 = "[WPORTAL_ERR]%s()/%d failed to malloc.\n";
      uVar6 = 0x1ebd;
    }
    else {
      memset(__s,0,__n);
      if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d success malloc %d bytes memory.\n","wportal_db_nsa_rbtree_load"
               ,0x1ec1,__n);
      }
      sVar3 = fread(__s,1,__n,__stream);
      if (__n == sVar3) {
        if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[WPORTAL_DBG]%s()/%d read file %d bytes success\n","wportal_db_nsa_rbtree_load",
                 0x1ec9,__n);
        }
        fclose(__stream);
        if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[WPORTAL_DBG]%s()/%d file_data = %s\n","wportal_db_nsa_rbtree_load",0x1ecc,__s);
        }
        iVar1 = json_tokener_new();
        if (iVar1 == 0) {
          if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[WPORTAL_ERR]%s()/%d Create tokener failed.\n\n","jsonParseStr",0xbf);
          }
        }
        else {
          iVar2 = json_tokener_parse_ex(iVar1,__s,0xffffffff);
          if (*(int *)(iVar1 + 0x1c) == 0) {
            json_tokener_free(iVar1);
            if (iVar2 != 0) {
              uVar6 = json_object_object_get(iVar2,"send_array");
              iVar1 = json_object_array_length(uVar6);
              for (iVar2 = 0; iVar2 < iVar1; iVar2 = iVar2 + 1) {
                uVar4 = json_object_array_get_idx(uVar6,iVar2);
                _wportal_nsa_add(uVar4,0);
              }
              FUN_00407df0(__s);
              return 0;
            }
          }
          else {
            if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[WPORTAL_ERR]%s()/%d Parse buf failed,%s.\n\n","jsonParseStr",0xc6,__s);
            }
            json_tokener_free(iVar1);
          }
        }
        if ((wportal_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
        goto LAB_00434b0c;
        pcVar5 = "[WPORTAL_ERR]%s()/%d get jsonrpc obj failed.\n";
        uVar6 = 0x1ed0;
      }
      else {
        if ((wportal_debug_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
        goto LAB_00434b0c;
        pcVar5 = "[WPORTAL_DBG]%s()/%d read data failed.\n";
        uVar6 = 0x1ec6;
      }
    }
  }
  else {
    __s = (void *)0x0;
    if ((wportal_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00434b0c;
    pcVar5 = "[WPORTAL_ERR]%s()/%d file_size is zero or no right.\n";
    uVar6 = 0x1eb5;
  }
  printf(pcVar5,"wportal_db_nsa_rbtree_load",uVar6);
LAB_00434b0c:
  fclose(__stream);
  if (__s != (void *)0x0) {
    FUN_00407df0(__s);
  }
  return 0xffffffff;
}


// func _apdb_parse_rrst_region_code_list_from_apdb @ 005f9abc size=276

undefined4 _apdb_parse_rrst_region_code_list_from_apdb(char *param_1,int param_2)

{
  size_t sVar1;
  undefined4 uVar2;
  int iVar3;
  char local_28 [12];
  
  local_28[0] = '\0';
  local_28[1] = '\0';
  local_28[2] = 0;
  if ((param_1 == (char *)0x0) || (iVar3 = 0, param_2 == 0)) {
    uVar2 = 0xffffffff;
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : _apdb_parse_rrst_region_code_list_from_apdb input error\n",
             "_apdb_parse_rrst_region_code_list_from_apdb",0x168b);
    }
  }
  else {
    do {
      if (*(char *)(param_2 + iVar3) == '\x01') {
        snprintf(local_28,3,"%d ",iVar3);
        sVar1 = strlen(param_1);
        strncat(param_1,local_28,200 - sVar1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 0x20);
    sVar1 = strlen(param_1);
    if (-1 < (int)(sVar1 - 1)) {
      param_1 = param_1 + (sVar1 - 1);
    }
    *param_1 = '\0';
    uVar2 = 0;
  }
  return uVar2;
}


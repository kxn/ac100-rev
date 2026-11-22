// func _apmngr_db_search_check @ 0054ad64 size=640

/* WARNING: Removing unreachable block (ram,0x0054af40) */
/* WARNING: Removing unreachable block (ram,0x0054af88) */

bool _apmngr_db_search_check(int param_1,char *param_2,char *param_3)

{
  int iVar1;
  size_t __n;
  int iVar2;
  char *pcVar3;
  char local_178 [218];
  char acStack_9e [65];
  char local_5d [77];
  
  iVar1 = strcmp(param_2,"entry_name");
  pcVar3 = (char *)(param_1 + 0x4e);
  if (iVar1 != 0) {
    iVar1 = strcmp(param_2,"model_name");
    if (iVar1 == 0) {
      iVar1 = apdb_get_ap_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,local_178);
      if (iVar1 != 0) {
        return false;
      }
      pcVar3 = local_5d;
      if (local_5d[0] == '\0') {
        pcVar3 = acStack_9e;
      }
      __n = strlen(pcVar3);
      iVar1 = strncmp(pcVar3,param_3,__n);
      return iVar1 == 0;
    }
    iVar1 = strcmp(param_2,"mac");
    if (iVar1 == 0) {
      local_178[0] = '\0';
      local_178[1] = '\0';
      local_178[2] = '\0';
      local_178[3] = '\0';
      local_178[4] = '\0';
      local_178[5] = '\0';
      local_178[6] = '\0';
      local_178[7] = '\0';
      local_178[8] = '\0';
      local_178[9] = '\0';
      local_178[10] = '\0';
      local_178[0xb] = '\0';
      local_178[0xc] = '\0';
      local_178[0xd] = '\0';
      local_178[0xe] = '\0';
      local_178[0xf] = '\0';
      local_178[0x10] = '\0';
      local_178[0x11] = '\0';
      local_178[0x12] = '\0';
      local_178[0x13] = '\0';
      FUN_00522838(param_3);
      mac2str(param_1 + 0x48,local_178,0x14);
      pcVar3 = local_178;
    }
    else {
      iVar1 = strcmp(param_2,"ip");
      if (iVar1 != 0) {
        iVar1 = strcmp(param_2,"link_status");
        if (iVar1 == 0) {
          if (1 < *(int *)(param_1 + 0x2ac) - 2U) {
            iVar1 = atoi(param_3);
            return iVar1 == 2;
          }
          iVar1 = multi_link_status_get(*(undefined2 *)(param_1 + 0x10));
          iVar2 = atoi(param_3);
          return iVar1 == iVar2;
        }
        iVar1 = strcmp(param_2,"support_func");
        if (iVar1 == 0) {
          iVar2 = atoi(param_3);
          iVar1 = iVar2;
          if (iVar2 < 0) {
            iVar1 = iVar2 + 0x1f;
          }
          return (1 << (iVar2 % 0x20 & 0x1fU) & *(uint *)(param_1 + ((iVar1 >> 5) + 0x94) * 4)) != 0
          ;
        }
        iVar1 = strcmp(param_2,"unsupport_func");
        if (iVar1 != 0) {
          return true;
        }
        iVar2 = atoi(param_3);
        iVar1 = iVar2;
        if (iVar2 < 0) {
          iVar1 = iVar2 + 0x1f;
        }
        return (1 << (iVar2 % 0x20 & 0x1fU) & *(uint *)(param_1 + ((iVar1 >> 5) + 0x94) * 4)) == 0;
      }
      pcVar3 = local_178;
      memset(pcVar3,0,0x40);
      FUN_00408190(*(undefined4 *)(param_1 + 0x26c),*(undefined4 *)(param_1 + 0x270),
                   *(undefined4 *)(param_1 + 0x274),*(undefined4 *)(param_1 + 0x278),
                   *(undefined4 *)(param_1 + 0x27c),pcVar3,0x40,0);
    }
  }
  pcVar3 = strstr(pcVar3,param_3);
  return pcVar3 != (char *)0x0;
}


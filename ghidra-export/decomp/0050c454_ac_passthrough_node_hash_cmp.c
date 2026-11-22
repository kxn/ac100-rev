// func ac_passthrough_node_hash_cmp @ 0050c454 size=224

bool ac_passthrough_node_hash_cmp(int param_1,void *param_2)

{
  int iVar1;
  bool bVar2;
  
  if ((param_1 == 0) || (param_2 == (void *)0x0)) {
    bVar2 = false;
    if (ac_passthrough_err_switch != '\0') {
      printf("[AC_PASSTHROUGH_ERROR]%s()/%d inputs error.\n","ac_passthrough_node_hash_cmp",0x3ca);
    }
  }
  else {
    if (ac_passthrough_debug_switch != '\0') {
      printf("[AC_PASSTHROUGH_DEBUG]%s()/%d key:%s\n","ac_passthrough_node_hash_cmp",0x3cd,param_2);
    }
    if (ac_passthrough_debug_switch != '\0') {
      printf("[AC_PASSTHROUGH_DEBUG]%s()/%d timeout:%s\n","ac_passthrough_node_hash_cmp",0x3cf,
             param_1 + 0x10);
    }
    iVar1 = memcmp((void *)(param_1 + 0x10),param_2,6);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}


// func _mesh_db_discover_link_info_compare @ 004b68a0 size=112

undefined4 _mesh_db_discover_link_info_compare(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    if (*(char *)(param_1 + 4) == '\x01') {
      if (*(char *)(param_2 + 4) == '\x02') {
        return 1;
      }
    }
    else if ((*(char *)(param_1 + 4) == '\x02') && (*(char *)(param_2 + 4) == '\x01')) {
      return 0xffffffff;
    }
    if (*(char *)(param_1 + 5) != *(char *)(param_2 + 5)) {
      uVar1 = 1;
      if (*(char *)(param_1 + 5) <= *(char *)(param_2 + 5)) {
        uVar1 = 0xffffffff;
      }
      return uVar1;
    }
  }
  return 0;
}


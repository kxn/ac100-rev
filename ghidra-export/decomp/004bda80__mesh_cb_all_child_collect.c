// func _mesh_cb_all_child_collect @ 004bda80 size=68

undefined4 _mesh_cb_all_child_collect(int param_1,int *param_2)

{
  int iVar1;
  
  if ((param_2 != (int *)0x0) && (iVar1 = *param_2, iVar1 < param_2[1])) {
    *(undefined2 *)(param_2[2] + iVar1 * 2) = *(undefined2 *)(param_1 + 0x10);
    *param_2 = iVar1 + 1;
    return 0;
  }
  return 2;
}


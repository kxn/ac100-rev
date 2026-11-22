// func _mesh_cb_child_collect @ 004bda44 size=60

undefined4 _mesh_cb_child_collect(int param_1,int *param_2)

{
  int iVar1;
  
  if ((param_2 != (int *)0x0) && (iVar1 = *param_2, iVar1 < 0x32)) {
    *(undefined2 *)((int)param_2 + iVar1 * 2 + 4) = *(undefined2 *)(param_1 + 0xc);
    *param_2 = iVar1 + 1;
    return 0;
  }
  return 2;
}


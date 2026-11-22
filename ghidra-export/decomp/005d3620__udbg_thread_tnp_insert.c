// func _udbg_thread_tnp_insert @ 005d3620 size=92

void _udbg_thread_tnp_insert(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &task_need_pstack;
  while ((iVar1 < tnp_cnt && (*piVar2 != param_1))) {
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  }
  if (iVar1 != tnp_cnt) {
    return;
  }
  tnp_cnt = iVar1 + 1;
  (&task_need_pstack)[iVar1] = param_1;
  return;
}


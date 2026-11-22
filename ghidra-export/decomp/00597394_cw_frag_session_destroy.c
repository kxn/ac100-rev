// func cw_frag_session_destroy @ 00597394 size=76

void cw_frag_session_destroy(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  if (*(code **)(param_1 + 0x40) != (code *)0x0) {
    (**(code **)(param_1 + 0x40))();
  }
  FUN_00407df0(param_1);
  return;
}


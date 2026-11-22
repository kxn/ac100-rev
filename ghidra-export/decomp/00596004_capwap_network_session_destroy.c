// func capwap_network_session_destroy @ 00596004 size=24

void capwap_network_session_destroy(int param_1)

{
  if (param_1 != 0) {
    capwap_network_free();
    return;
  }
  return;
}


; func cw_priv_two_way_passthrough_general_info_request_free @ 0x005ca064 size=0x58
  5ca064:	27bdffd8 	addiu	sp,sp,-40
  5ca068:	afb10020 	sw	s1,32(sp)
  5ca06c:	afbf0024 	sw	ra,36(sp)
  5ca070:	afb0001c 	sw	s0,28(sp)
  5ca074:	8c900010 	lw	s0,16(a0)
  5ca078:	1200000a 	beqz	s0,0x5ca0a4
  5ca07c:	00808821 	move	s1,a0
  5ca080:	8e04000c 	lw	a0,12(s0)
  5ca084:	10800004 	beqz	a0,0x5ca098
  5ca088:	00000000 	nop
  5ca08c:	0c101f7c 	jal	0x407df0
  5ca090:	00000000 	nop
  5ca094:	ae00000c 	sw	zero,12(s0)
  5ca098:	0c101f7c 	jal	0x407df0
  5ca09c:	8e240010 	lw	a0,16(s1)
  5ca0a0:	ae200010 	sw	zero,16(s1)
  5ca0a4:	8fbf0024 	lw	ra,36(sp)
  5ca0a8:	00001021 	move	v0,zero
  5ca0ac:	8fb10020 	lw	s1,32(sp)
  5ca0b0:	8fb0001c 	lw	s0,28(sp)
  5ca0b4:	03e00008 	jr	ra
  5ca0b8:	27bd0028 	addiu	sp,sp,40

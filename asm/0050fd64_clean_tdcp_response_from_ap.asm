; func clean_tdcp_response_from_ap @ 0x0050fd64 size=0x24
  50fd64:	10800004 	beqz	a0,0x50fd78
  50fd68:	00c01821 	move	v1,a2
  50fd6c:	80820000 	lb	v0,0(a0)
  50fd70:	14400003 	bnez	v0,0x50fd80
  50fd74:	00000000 	nop
  50fd78:	08142c60 	j	0x50b180
  50fd7c:	00602021 	move	a0,v1
  50fd80:	081433b4 	j	0x50ced0
  50fd84:	00000000 	nop

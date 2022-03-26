from twilio.rest import Client

account_sid = 'ACcdd58da89dcd1f5f44cb0016fa50a988'
auth_token = '4e0876651575da7be4f38924f45d40c1'
client = Client(account_sid,auth_token)

call = client.calls.create(
   twiml = '<Response><Say>hello Klee here</Say></Response',
   to = '+306987862288',
   from_ = '+12566336890'
)
print(call.sid)
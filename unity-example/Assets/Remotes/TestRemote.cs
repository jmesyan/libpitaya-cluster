using System;
using Google.Protobuf;
using Pitaya;

class TestRemote : BaseRemote
{
    public Protos.RPCRes remote(Protos.RPCMsg msg)
    {
        Protos.RPCRes response = new Protos.RPCRes();
        response.Msg = String.Format("hello from unity :) {0}", System.Guid.NewGuid().ToString());
        response.Code = 200;
        Console.WriteLine("remote executed with arg {0}", msg);
        return response;
    }
}
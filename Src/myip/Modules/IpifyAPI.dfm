object DmIpifyAPI: TDmIpifyAPI
  OldCreateOrder = False
  Height = 152
  Width = 204
  object RESTClient: TRESTClient
    Accept = 'application/json, text/plain; q=0.9, text/html;q=0.8,'
    AcceptCharset = 'utf-8, *;q=0.8'
    BaseURL = 'https://api.ipify.org'
    Params = <>
    Left = 32
    Top = 16
  end
  object RESTRequest: TRESTRequest
    AssignedValues = [rvConnectTimeout, rvReadTimeout]
    Client = RESTClient
    Params = <
      item
        Name = 'format'
        Value = 'json'
      end>
    Response = RESTResponse
    Left = 120
    Top = 16
  end
  object RESTResponse: TRESTResponse
    ContentType = 'application/json'
    Left = 32
    Top = 72
  end
end

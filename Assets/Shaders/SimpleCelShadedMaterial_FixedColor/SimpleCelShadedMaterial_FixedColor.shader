{
    "Source": "SimpleCelShadedMaterial_FixedColor.azsl",
    "DepthStencilState": {
        "Depth": {
            "Enable": true,
            "CompareFunc": "GreaterEqual"
        },
        "Stencil" :
        {
            "Enable": true,
            "ReadMask": "0x00",
            // Allow all stencil bits except 0x80 which would enabled `UseDiffuseGIPass`. We don't want post-forward-pass lighting features to affect our clean cel shaded results.
            "WriteMask": "0x7F",
            "FrontFace":
            {
                "Func": "Always",
                "DepthFailOp": "Keep",
                "FailOp": "Keep",
                "PassOp": "Replace"
            }
        }
    },
    "ProgramSettings": {
        "EntryPoints": [
            {
                "name": "MinimalPBR_MainPassVS",
                "type": "Vertex"
            },
            {
                "name": "MinimalPBR_MainPassPS",
                "type": "Fragment"
            }
        ]
    },
    "DrawList": "forward"
}

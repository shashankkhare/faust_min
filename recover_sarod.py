import json

with open('/home/shashankkhare/.gemini/antigravity/brain/0dfab3ad-819b-4460-822f-d038691e83eb/.system_generated/logs/transcript.jsonl', 'r') as f:
    lines = f.readlines()

for line in lines:
    try:
        data = json.loads(line)
        if data.get('type') == 'PLANNER_RESPONSE':
            for tc in data.get('tool_calls', []):
                if tc.get('name') in ['replace_file_content', 'multi_replace_file_content']:
                    args = tc.get('args', {})
                    if 'sarod.dsp' in args.get('TargetFile', ''):
                        print("FOUND DIFF at", data.get('created_at'))
                        print(args.get('TargetContent', ''), "->", args.get('ReplacementContent', ''))
                        print("---")
                        if 'ReplacementChunks' in args:
                            print(args.get('ReplacementChunks'))
                            print("---")
    except Exception as e:
        pass

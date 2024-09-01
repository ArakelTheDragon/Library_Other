import discord
from discord.ext import commands

# Intents are needed to access certain events in Discord
intents = discord.Intents.default()
intents.messages = True  # Use 'intents.messages' instead of 'intents.message_content'

# Create an instance of the Bot with a command prefix
bot = commands.Bot(command_prefix='!', intents=intents)

# Event: When the bot has successfully connected to Discord
@bot.event
async def on_ready():
    print(f'Logged in as {bot.user.name} (ID: {bot.user.id})')
    print('------')

# Command: Responds to "!hello" with a greeting
@bot.command(name='hello')
async def hello(ctx):
    await ctx.send(f'Hello, {ctx.author.display_name}!')

# Command: Responds to "!add" with the sum of two numbers
@bot.command(name='add')
async def add(ctx, a: int, b: int):
    await ctx.send(f'The sum of {a} and {b} is {a + b}.')

# Run the bot with your token
bot.run('YOUR_BOT_TOKEN')

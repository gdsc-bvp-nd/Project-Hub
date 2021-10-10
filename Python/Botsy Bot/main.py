import Responses as Re
import Constants as Keys
from telegram.ext import *


print('Starting BotsyBot')


def start_command(update, context):
    update.message.reply_text('Hey! Type something to get started')


def handle_message(update, context):
    text = str(update.message.text).lower()
    response = Re.response(text)
    update.message.reply_text(response)


def main():
    updater = Updater(Keys.API_KEY, use_context=True)
    dp = updater.dispatcher

    dp.add_handler(CommandHandler('start', start_command))
    dp.add_handler(MessageHandler(Filters.text, handle_message))
    updater.start_polling()
    updater.idle()


main()
